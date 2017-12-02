"""
Author:     Brian Mascitello
Date:       12/2/2017
Websites:   http://adventofcode.com/2017/day/2
Info:       --- Day 2: Corruption Checksum ---
"""


def get_data(input_text):
    with open(input_text) as file:
        data_from_file = file.read()
    file.close()
    return data_from_file


data = get_data('Day2Q1 2017 Input.txt')

list_of_differences = list()  # The max - min of each row stored in this list.

# Reads the data one line at a time.
for line in data.splitlines():
    values = list(map(int, line.split('\t')))  # Converts each line to integer values in a list.
    difference = max(values) - min(values)  # Finds the difference of the largest and smallest numbers in values.
    list_of_differences.append(difference)  # Adds the difference to the list.

checksum = sum(list_of_differences)  # Sums together everything in the list.
print(checksum)  # 36174
