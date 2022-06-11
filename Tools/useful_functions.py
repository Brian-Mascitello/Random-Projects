from itertools import combinations
import jellyfish as jf
import math
import numpy as np
import regex as re
import pandas as pd


def categorize_relationship(df: pd.DataFrame, score: str = 'Edit_Score', overlap: str = 'Overlap',
                            winner: str = 'Winner') -> pd.DataFrame:
    """
    Adds a winner column to the df provided based on the score and overlap columns. The score is between 0 and 1, where
    0 would be no similarity, and 1 would be a perfect match and require no text edits. The overlap is False is there is
    no substring match, and True is there is a substring match in both of the columns being compared. Based on this
    info, the winner column will contain 6 matching categories.

    :param df:
    :param score:
    :param overlap:
    :param winner:
    :return:
    """

    winner = ensure_column_name_unique(df=df, column_name=winner)

    df[winner] = np.where((df[score] == 1) & (df[overlap]), '1) Perfect Match', '')
    df[winner] = np.where((df[winner] == '') & (df[score] >= 0.5) & (df[overlap]),
                          '2) Strong Overlap Match', df[winner])
    df[winner] = np.where((df[winner] == '') & (df[score] < 0.5) & (df[overlap]), '3) Weak Overlap Match', df[winner])
    df[winner] = np.where((df[winner] == '') & (df[score] >= 0.75) & (~df[overlap]),
                          '4) Strong Partial Match', df[winner])
    df[winner] = np.where((df[winner] == '') & (df[score] > 0.5) & (~df[overlap]), '5) Weak Partial Match', df[winner])
    df[winner] = np.where(df[winner] == '', '6) No Match', df[winner])

    return df


def clean_df_columns_for_comparisons(df: pd.DataFrame, df_columns: list[str], prefix: str = 'Cleaned_') -> \
        tuple[pd.DataFrame, list[str]]:
    """
    Fixes the columns names in df_columns, and prepares the string data in the columns for processing with the jellyfish
    package by reducing the characters to all letters and numbers lowercase single spaces.

    :param df:
    :param df_columns:
    :param prefix:
    :return:
    """

    new_columns = []
    for column in df_columns:
        new_column_name = prefix + column
        new_column_name = new_column_name.strip()
        new_column_name = re.sub(r'\s+', '_', new_column_name)
        new_column_name = ensure_column_name_unique(df=df, column_name=new_column_name)
        new_columns.append(new_column_name)

        df[new_column_name] = df[column]
        df[new_column_name] = df[new_column_name].replace('[^a-zA-Z0-9 ]', '', regex=True)
        df[new_column_name] = df[new_column_name].replace(r'\s+', ' ', regex=True)
        df[new_column_name] = df[new_column_name].str.lower()

    return df, new_columns


def convert_and_clean_combo(df: pd.DataFrame, df_columns: list[str], na_replacement: str = '',
                            prefix: str = 'Cleaned_') -> tuple[pd.DataFrame, list[str]]:
    """
    Fully prepares the df_columns for string comparisons with the jellyfish package.

    :param df:
    :param df_columns:
    :param na_replacement:
    :param prefix:
    :return:
    """

    df = convert_df_columns_to_str(df=df, df_columns=df_columns, na_replacement=na_replacement)
    df, new_columns = clean_df_columns_for_comparisons(df=df, df_columns=df_columns, prefix=prefix)

    return df, new_columns


def convert_df_columns_to_str(df: pd.DataFrame, df_columns: list[str], na_replacement: str = '') -> pd.DataFrame:
    """
    Ensures the values in the df_columns are string type, useful for comparisons.

    :param df:
    :param df_columns:
    :param na_replacement:
    :return:
    """

    for column in df_columns:
        df[column] = df[column].replace(to_replace=np.nan, value=na_replacement, regex=True)
        df[column] = df[column].astype(str)
        df[column] = df[column].str.strip()

    return df


def edit_score_calculator(df: pd.DataFrame, compare_1: str, compare_2: str, edit_distance_column: str) -> float:
    """
    Creates a score based on the result from the jellyfish calculation and the length of the compare_1 and compare_2
    words. Longer words should have a higher score if they are missing the same number of letters as a shorter word. A
    minimum length of 0 cannot be properly compared, so it returns 0. An edit distance of zero means the words are a
    perfect match, returning a 1 as in 100% match. Everything else will be a decimal less than 1, including 0 if the
    words are entirely different.

    :param df:
    :param compare_1:
    :param compare_2:
    :param edit_distance_column:
    :return:
    """

    edit_distance = int(df[edit_distance_column])
    max_length = max(len(df[compare_1]), len(df[compare_2]))
    min_length = min(len(df[compare_1]), len(df[compare_2]))

    if min_length == 0:
        return 0
    elif edit_distance == 0:
        return 1
    else:
        return 1 - (edit_distance / max_length)


def ensure_column_name_unique(df: pd.DataFrame, column_name: str) -> str:
    """
    Ensures the column_name is unique before using it in the df. If column_name is not in the columns already, returns
    column_name as is, otherwise it will add '_n' to the name, where n is an integer greater than 0.

    :param df:
    :param column_name:
    :return:
    """

    if column_name in df.columns:
        base_column_name = column_name
        suffix_counter = 1
        while column_name in df.columns:
            column_name = base_column_name + '_' + str(suffix_counter)
            suffix_counter = suffix_counter + 1

    return column_name


def fuzzy_compare_columns(df: pd.DataFrame, df_columns: list[str]) -> pd.DataFrame:
    """
    Combines the capabilities of convert_and_clean_combo and score_and_categorize_combo. Given the DataFrame df and the
    list of column names df_columns to compare, returns a DataFrame with categorized columns of each size two
    combination of the df_columns.

    :param df:
    :param df_columns:
    :return:
    """

    assert isinstance(df, pd.DataFrame)
    assert all(isinstance(column, str) for column in df_columns)
    assert len(df_columns) > 1

    df, df_new_columns = convert_and_clean_combo(df=df, df_columns=df_columns)

    for column_1, column_2 in list(combinations(df_new_columns, 2)):
        df = score_and_categorize_combo(df=df, column_1=column_1, column_2=column_2, drop=True)

    return df


def overlap_df_columns(df: pd.DataFrame, column_1: str, column_2: str) -> bool:
    """
    Compares the column_1 and column_2 values to see if they match up or contain substrings within each other. If they
    do, return True, if there's no full or partial substring combination, return False. This is usually a good indicator
    if two string are similar in addition to an edit distance.

    :param df:
    :param column_1:
    :param column_2:
    :return:
    """

    if min(len(df[column_1]), len(df[column_2])) == 0:
        return False
    elif df[column_1] == df[column_2]:
        return True
    elif str(df[column_1]).lower().strip() in str(df[column_2]).lower().strip():
        return True
    elif str(df[column_2]).lower().strip() in str(df[column_1]).lower().strip():
        return True
    elif all(item in str(df[column_1]).lower().strip().split() for item in str(df[column_2]).lower().strip().split()):
        return True
    elif all(item in str(df[column_2]).lower().strip().split() for item in str(df[column_1]).lower().strip().split()):
        return True
    else:
        return False


def score_and_categorize_combo(df: pd.DataFrame, column_1: str, column_2: str, drop: bool = True) -> pd.DataFrame:
    """
    Measures the text edit distance with a Damerau–Levenshtein method from the jellyfish package. The utilizes the
    edit_score_calculator to get a value of 0 = not at all similar to 1 = perfect matches using the edit distance. The
    next step calculates whether the values are substring matches or not. Finally, using the score and overlap, this
    will categorize the row in df, usually from 1-6 in ascending order, 1 a perfect match to 6 not at all a match.

    :param df:
    :param column_1:
    :param column_2:
    :param drop:
    :return:
    """

    distance_name = ensure_column_name_unique(df=df, column_name='Edit_Distance')
    score_name = ensure_column_name_unique(df=df, column_name='Edit_Score')
    overlap_name = ensure_column_name_unique(df=df, column_name='Overlap')

    winner_name = column_1 + ' & ' + column_2
    winner_name = winner_name.replace('Cleaned_', '')
    winner_name = ensure_column_name_unique(df=df, column_name=winner_name)

    df[distance_name] = df.apply(lambda x: jf.damerau_levenshtein_distance(x[column_1], x[column_2]), axis=1)
    df[score_name] = df.apply(edit_score_calculator, compare_1=column_1, compare_2=column_2,
                              edit_distance_column=distance_name, axis=1)
    df[overlap_name] = df.apply(overlap_df_columns, column_1=column_1, column_2=column_2, axis=1)

    df = categorize_relationship(df=df, score=score_name, overlap=overlap_name, winner=winner_name)

    if drop:
        df = df.drop(columns=[distance_name, score_name, overlap_name])

    return df


def write_excel_with_widths(df: pd.DataFrame, writer: pd.ExcelWriter, sheet_name: str, min_width: int = 8,
                            max_width: int = 48, header_buffer: int = 4, index=False) -> None:
    """
    Automatically format Excel column width and writes the df to an Excel file.

    :param df:
    :param writer:
    :param sheet_name:
    :param min_width:
    :param max_width:
    :param header_buffer:
    :param index:
    :return:

    with pd.ExcelWriter('new_excel_file.xlsx', engine='xlsxwriter') as writer:
        for df, sn in zip(dfs, sns):
        write_excel_with_widths(df=df, writer=writer, sheet_name=sn, index=False)
    """

    df.to_excel(writer, sheet_name=sheet_name, index=index)

    for column in df.columns:
        column_length = max(len(column) + header_buffer, df[column].astype(str).map(len).max())

        column_length = math.ceil(column_length)
        if column_length < min_width:
            column_length = min_width
        elif column_length > max_width:
            column_length = max_width

        column_index = df.columns.get_loc(column)
        writer.sheets[sheet_name].set_column(column_index, column_index, column_length)
