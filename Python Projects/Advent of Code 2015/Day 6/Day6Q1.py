# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/23/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/6
            http://adventofcode.com/day/6/input
Info:       --- Day 6: Probably a Fire Hazard ---

    Because your neighbors keep defeating you in the holiday house decorating
    contest year after year, you've decided to deploy one million lights in a
    1000x1000 grid.

    Furthermore, because you've been especially nice this year, Santa has
    mailed you instructions on how to display the ideal lighting configuration.

    Lights in your grid are numbered from 0 to 999 in each direction; the
    lights at each corner are at 0,0, 0,999, 999,999, and 999,0. The
    instructions include whether to turn on, turn off, or toggle various
    inclusive ranges given as coordinate pairs. Each coordinate pair represents
    opposite corners of a rectangle, inclusive; a coordinate pair like 0,0
    through 2,2 therefore refers to 9 lights in a 3x3 square. The lights all
    start turned off.

    To defeat your neighbors this year, all you have to do is set up your
    lights by doing the instructions Santa sent you in order.

    For example:

    - turn on 0,0 through 999,999 would turn on (or leave on) every light.
    - toggle 0,0 through 999,0 would toggle the first line of 1000 lights,
    turning off the ones that were on, and turning on the ones that were off.
    - turn off 499,499 through 500,500 would turn off (or leave off) the middle
    four lights.
    
    After following the instructions, how many lights are lit?
"""

import numpy as np

def on_off_lights(input_str_array, input_lights):
    # Turns lights off in given dimensions.

    x1, y1 = input_str_array[2].split(',')
    x1, y1 = int(x1), int(y1)
    
    x2, y2 = input_str_array[4].split(',')
    x2, y2 = int(x2) + 1, int(y2) + 1 # Added one to include the index given.
    
    if input_str_array[1] == 'on':
        
        input_lights[x1:x2, y1:y2] = 1
        
    else:
        
        input_lights[x1:x2, y1:y2] = 0
        
    return input_lights

def toggle_lights(input_str_array, input_lights):
    # Switch lights that are on to off, and lights that are off to on.

    x1, y1 = input_str_array[1].split(',')
    x1, y1 = int(x1), int(y1)
    
    x2, y2 = input_str_array[3].split(',')
    x2, y2 = int(x2) + 1, int(y2) + 1 # Added one to include the index given.
    
    # This should turn all the zeros to ones and vice versa.
    input_lights[x1:x2, y1:y2] = np.logical_not(input_lights[x1:x2, y1:y2])
    
    return input_lights
    
###############################################################################

million_lights = np.zeros((1000, 1000), dtype=np.int)

with open('Day6Q1 Input.txt') as current:
    # Term "current" is the file that's opened.

    for line in current:
        # Goes through each line in the open file "current".
        
        string_array = line.split()
        
        # print(string_array) # used to check string_array
        
        if string_array[0] == 'toggle':
            
            million_lights = toggle_lights(string_array, million_lights)
            
        else:
            
            million_lights = on_off_lights(string_array, million_lights)

print(np.sum(million_lights)) # 400410