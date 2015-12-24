# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/23/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/6
            http://adventofcode.com/day/6/input
Info:       --- Part Two ---

    You just finish implementing your winning light pattern when you realize
    you mistranslated Santa's message from Ancient Nordic Elvish.

    The light grid you bought actually has individual brightness controls; each
    light can have a brightness of zero or more. The lights all start at zero.

    The phrase turn on actually means that you should increase the brightness
    of those lights by 1.

    The phrase turn off actually means that you should decrease the brightness
    of those lights by 1, to a minimum of zero.

    The phrase toggle actually means that you should increase the brightness of
    those lights by 2.
    
    What is the total brightness of all lights combined after following Santa's
    instructions?

    For example:

    - turn on 0,0 through 0,0 would increase the total brightness by 1.
    - toggle 0,0 through 999,999 would increase the total brightness by
    2000000.
"""

import numpy as np

def on_off_lights(input_str_array, input_lights):
    # Turns lights off in given dimensions.

    x1, y1 = input_str_array[2].split(',')
    x1, y1 = int(x1), int(y1)
    
    x2, y2 = input_str_array[4].split(',')
    x2, y2 = int(x2) + 1, int(y2) + 1 # Added one to include the index given.
    
    if input_str_array[1] == 'on':
        
        input_lights[x1:x2, y1:y2] += 1
        
    else:
        
        for i in range(x1, x2):
            for j in range(y1, y2):
                if input_lights[i, j] > 0:
                    input_lights[i, j] -= 1
    
    return input_lights

def toggle_lights(input_str_array, input_lights):
    # Switch lights that are on to off, and lights that are off to on.

    x1, y1 = input_str_array[1].split(',')
    x1, y1 = int(x1), int(y1)
    
    x2, y2 = input_str_array[3].split(',')
    x2, y2 = int(x2) + 1, int(y2) + 1 # Added one to include the index given.
    
    # This should turn all the zeros to ones and vice versa.
    input_lights[x1:x2, y1:y2] += 2
    
    return input_lights
    
###############################################################################

million_lights = np.zeros((1000, 1000), dtype=np.int)

with open('Day6Q1 Input.txt') as current:
    # Term "current" is the file that's opened.

    for line in current:
        # Goes through each line in the open file "current".
        
        string_array = line.split()
        
        if string_array[0] == 'toggle':
            
            million_lights = toggle_lights(string_array, million_lights)
            
        else:
            
            million_lights = on_off_lights(string_array, million_lights)

print(np.sum(million_lights)) # 15343601