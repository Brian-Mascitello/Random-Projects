# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/19/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/1
            http://adventofcode.com/day/1/input   
Info:       --- Part Two ---

    Now, given the same instructions, find the position of the first character
    that causes him to enter the basement (floor -1). The first character in
    the instructions has position 1, the second character has position 2, and
    so on.
    
    For example:
    
    - ) causes him to enter the basement at character position 1.
    - ()()) causes him to enter the basement at character position 5.
    - What is the position of the character that causes Santa to first enter
        the basement?
"""

file = open('Day1Q1 2016 Input.txt')
input_string = file.read()
file.close()

current_floor = 0

for i in range(0, len(input_string)):
    if current_floor < 0:
        # As soon as current_floor is in the basement, print the position of
        # the character that causes Santa to first enter the basement.
        print(i)
        break
    
    if input_string[i] == '(':
        current_floor += 1
    elif input_string[i] == ')':
        current_floor -= 1