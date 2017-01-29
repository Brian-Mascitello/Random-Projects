# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/28/2017
School:     Arizona State University
Websites:   http://adventofcode.com/2015/day/8
Info:       --- Day 8: Matchsticks ---
"""

with open('Day8Q1 2015 Input.txt') as openfile:

    number_characters_string_code = 0

    for current_line in openfile:

        number_characters_string_code += len(current_line.strip()) - len(eval(current_line))

print(number_characters_string_code)  # 1350
