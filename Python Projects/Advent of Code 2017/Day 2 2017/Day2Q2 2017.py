"""
Author:     Brian Mascitello
Date:       12/2/2017
Websites:   http://adventofcode.com/2017/day/2
Info:       --- Day 2: Corruption Checksum ---
            --- Part Two ---
"""


def get_data(input_text):
    with open(input_text) as file:
        data_from_file = file.read()
    file.close()
    return data_from_file


def find_divisible(list_of_values):
    list_of_values.sort()  # Sorts the values list in ascending order.
    index = 1
    for divisor in list_of_values:
        for position in range(index, len(list_of_values)):
            dividend = float(list_of_values[position])
            quotient = dividend / divisor
            if quotient.is_integer():
                return int(quotient)
        index += 1
    return 0


data = get_data('Day2Q1 2017 Input.txt')

list_of_dividers = list()  # The max - min of each row stored in this list.

# Reads the data one line at a time.
for line in data.splitlines():
    values = list(map(int, line.split('\t')))  # Converts each line to integer values in a list.
    divider = find_divisible(values)  # Iterates through values to find which number divides evenly into a larger one.
    list_of_dividers.append(divider)  # Adds the divider to the list.

checksum = sum(list_of_dividers)  # Sums together everything in the list.
print(checksum)  # 244
