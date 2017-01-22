# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/19/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/2
            http://adventofcode.com/day/2/input   
Info:       --- Day 2: I Was Told There Would Be No Math ---

    The elves are running low on wrapping paper, and so they need to submit an
    order for more. They have a list of the dimensions (length l, width w, and
    height h) of each present, and only want to order exactly as much as they
    need.

    Fortunately, every present is a box (a perfect right rectangular prism),
    which makes calculating the required wrapping paper for each gift a little
    easier: find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l.
    The elves also need a little extra paper for each present: the area of the
    smallest side.

    For example:

    - A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square
    feet of wrapping paper plus 6 square feet of slack, for a total of 58
    square feet.
    - A present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square
    feet of wrapping paper plus 1 square foot of slack, for a total of 43
    square feet.
    
    All numbers in the elves' list are in feet. How many total square feet of
    wrapping paper should they order?
"""

dimensions_array = []
total_paper_needed = 0;

with open('Day2Q1 Input.txt') as current:
    # Term "current" is the file that's opened.

    for line in current:
        # Goes through each line in the open file "current".
        
        # Resets the dimensions array so it is fresh for next iteration.
        dimensions_array = []
        
        length, width, height = line.split('x', 2)
        # Delimits the each line to three separate parts
        
        # Adds the terms of the line to an array and sorts to ascending order.
        dimensions_array.append(int(length))
        dimensions_array.append(int(width))
        dimensions_array.append(int(height))
        dimensions_array.sort()
        
        # For readability, assigns each area size to a variable.
        smallest = dimensions_array[0] * dimensions_array[1]
        medium = dimensions_array[0] * dimensions_array[2]
        largest = dimensions_array[1] * dimensions_array[2]
        
        # Adds the surface area plus an extra smallest side for slack.
        total_paper_needed += 3 * smallest + 2 * medium + 2 * largest
        
# print(dimensions_array) # Used to test array, final one should be [5, 11, 23]
print(total_paper_needed) # Total square feet of wrapping paper needed.