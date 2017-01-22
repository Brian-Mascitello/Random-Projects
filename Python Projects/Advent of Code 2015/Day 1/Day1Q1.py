# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/19/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/1
            http://adventofcode.com/day/1/input   
Info:       --- Day 1: Not Quite Lisp ---

Santa was hoping for a white Christmas, but his weather machine's "snow"
function is powered by stars, and he's fresh out! To save Christmas, he needs
you to collect fifty stars by December 25th.

Collect stars by helping Santa solve puzzles. Two puzzles will be made
available on each day in the advent calendar; the second puzzle is unlocked
when you complete the first. Each puzzle grants one star. Good luck!

Here's an easy puzzle to warm you up.
Santa is trying to deliver presents in a large apartment building, but he can't
find the right floor - the directions he got are a little confusing. He starts
on the ground floor (floor 0) and then follows the instructions one character
at a time.

An opening parenthesis, (, means he should go up one floor, and a closing
parenthesis, ), means he should go down one floor.

The apartment building is very tall, and the basement is very deep; he will
never find the top or bottom floors.

For example:

(()) and ()() both result in floor 0.
((( and (()(()( both result in floor 3.
))((((( also results in floor 3.
()) and ))( both result in floor -1 (the first basement level).
))) and )())()) both result in floor -3.
To what floor do the instructions take Santa?
"""

file = open('Day1Q1 2016 Input.txt')
input_string = file.read()
file.close()

#print(input_string) # Made to verify input string.
#print(len(input_string)) # Made to verify input string length.

count_left_positive = 0 # Counts the floors Santa goes up.
count_right_negative = 0 # Counts the floors Santa goes down.

for i in range(0, len(input_string)):
    if input_string[i] == '(':
        count_left_positive += 1
    elif input_string[i] == ')':
        count_right_negative += 1
        
# print(count_left_positive)
# print(count_right_negative)
print(count_left_positive - count_right_negative) # Floor Santa needs.