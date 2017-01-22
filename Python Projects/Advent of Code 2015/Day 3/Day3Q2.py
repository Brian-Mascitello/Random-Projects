# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/20/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/3
            http://adventofcode.com/day/3/input   
Info:       --- Part Two ---

    The next year, to speed up the process, Santa creates a robot version of
    himself, Robo-Santa, to deliver presents with him.

    Santa and Robo-Santa start at the same location (delivering two presents to
    the same starting house), then take turns moving based on instructions from
    the elf, who is eggnoggedly reading from the same script as the previous
    year.

    This year, how many houses receive at least one present?

    For example:

    - ^v delivers presents to 3 houses, because Santa goes north, and then 
    Robo-Santa goes south.
    - ^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up
    back where they started.
    - ^v^v^v^v^v now delivers presents to 11 houses, with Santa going one
    direction and Robo-Santa going the other.
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
    # Should be the same since this accounts for max distance in each direction.

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
x_robot = horizon_mid
y_robot = vert_mid

for i in range(0, len(input_string)):
    # Adds presents Santa gives to locations in the array.

    if i % 2 == 0:
        # If even Santa moves, otherwise the robot moves.
    
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
        
    else:
        
        neighborhood[x_robot][y_robot] += 1 # Adds a gift the robot places.
        
        # This switch statement moves the robot.
        if input_string[i] == '^':
            y_robot += 1
        elif input_string[i] == '>':
            x_robot += 1
        elif input_string[i] == 'v':
            y_robot -= 1
        elif input_string[i] == '<':
            x_robot -= 1
        
        neighborhood[x_robot][y_robot] += 1

homes_with_gifts = 0 # Will be the number of homes with at least one present.

# Iterates through neighborhood looking for homes with more than 0 presents.
for updown in range(0, vert_len):
   for leftright in range(0, horizon_len):
       if neighborhood[leftright][updown] > 0:
           homes_with_gifts += 1
           
print(homes_with_gifts) # 2639 homes are marked with at least one gift!