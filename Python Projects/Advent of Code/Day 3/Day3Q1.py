# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/19/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/3
            http://adventofcode.com/day/3/input   
Info:       --- Day 3: Perfectly Spherical Houses in a Vacuum ---

    Santa is delivering presents to an infinite two-dimensional grid of houses.

    He begins by delivering a present to the house at his starting location,
    and then an elf at the North Pole calls him via radio and tells him where
    to move next. Moves are always exactly one house to the north (^), south
    (v), east (>), or west (<). After each move, he delivers another present to
    the house at his new location.

    However, the elf back at the north pole has had a little too much eggnog,
    and so his directions are a little off, and Santa ends up visiting some
    houses more than once. How many houses receive at least one present?

    For example:

    - > delivers presents to 2 houses: one at the starting location, and one to
    the east.
    - ^>v< delivers presents to 4 houses in a square, including twice to the
    house at his starting/ending location.
    - ^v^v^v^v^v delivers a bunch of presents to some very lucky children at
    only 2 houses.
"""

import numpy as np

file = open('Day3Q1 Input.txt')
input_string = file.read()
file.close()

north = 0
east = 0
south = 0
west = 0

for i in range(0, len(input_string)):
    # Scans the input_string to find the furthest Santa travels in each direction.

    if input_string[i] == '^':
        north += 1
    elif input_string[i] == '>':
        east += 1
    elif input_string[i] == 'v':
        south += 1
    elif input_string[i] == '<':
        west += 1
        
print(north, east, south, west) # Checks final values of the directions.

# horizontal_length and vertical_length for the size of 2D array Santa will traverse.
# The midpoints will be the starting location in the center of the 2D array
if north > south:
    vertical_midpoint = north
    vertical_length = 2 * north + 1
else:
    vertical_midpoint = south
    vertical_length = 2 * south + 1

if east > west:
    horizontal_midpoint = east
    horizontal_length = 2 * east + 1
else:
    horizontal_midpoint = west
    horizontal_length = 2 * west + 1 

print(vertical_midpoint, vertical_length, horizontal_midpoint, horizontal_length)
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    