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
        
# print(north, east, south, west) # Checks final values of the directions.

# horizon_len and vert_len for the size of 2D array Santa will traverse.
# The midpoints will be the starting location in the center of the 2D array
if north > south:
    vert_mid = north
    vert_len = 2 * north + 1
else:
    vert_mid = south
    vert_len = 2 * south + 1

if east > west:
    horizon_mid = east
    horizon_len = 2 * east + 1
else:
    horizon_mid = west
    horizon_len = 2 * west + 1 

# print(vert_mid, vert_len, horizon_mid, horizon_len) # Checks the dimensions of the array.

# Zeros array of type int with dimensions (horizon_len, vert_len)
neighborhood = np.zeros((horizon_len, vert_len), dtype = np.int)

# print(neighborhood) # Checks array is right style.

# Makes two new variables for house locations.
x = horizon_mid
y = vert_mid

for i in range(0, len(input_string)):
    # Adds presents Santa gives to locations in the array.

    neighborhood[x][y] += 1 # Adds a gift to the house before moving.

    # This switch statement moves Santa.
    if input_string[i] == '^':
        y += 1
    elif input_string[i] == '>':
        x += 1
    elif input_string[i] == 'v':
        y -= 1
    elif input_string[i] == '<':
        x -= 1
        
    neighborhood[x][y] += 1 # Adds a gift to the house after moving.
    
homes_with_gifts = 0 # Will be the number of homes with at least one present.

# Iterates through neighborhood looking for homes with more than 0 presents.
for updown in range(0, vert_len):
   for leftright in range(0, horizon_len):
       if neighborhood[leftright][updown] > 0:
           homes_with_gifts += 1
           
print(homes_with_gifts) # 2565 homes are marked with at least one gift!