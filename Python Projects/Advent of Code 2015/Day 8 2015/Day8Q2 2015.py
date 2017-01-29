# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/28/2017
School:     Arizona State University
Websites:   http://adventofcode.com/2015/day/8
Info:       --- Day 8: Matchsticks ---
            --- Part Two ---
"""

with open('Day8Q1 2015 Input.txt') as openfile:

    number_characters_string_code = 0

    for line in openfile:

        line = line.strip()  # removes the \n after each line
        original_char_count = len(line)
        line = line.replace('\\', '\\\\')  # adds an additional \ for each \ in line
        line = line.replace('\"', '\\\"')  # adds an additional \ for each " in line
        line = '\"' + line + '\"'  # surrounds each line with a pair of double quotes

        number_characters_string_code += len(line) - original_char_count

print(number_characters_string_code)
