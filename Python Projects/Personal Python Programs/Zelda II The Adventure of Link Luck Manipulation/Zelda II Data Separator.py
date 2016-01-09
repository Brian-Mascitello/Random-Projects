# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://redcandle.us/
Info:       My attempts to solving the probability timings for the 50 Point Bag
    for the Zelda II community.
"""

def chance_converter(average):
    # Returns a float that is the percent chance of getting a PBag.

    return 1 - (average / 255) # Lower average = greater PBag chance.

def rolling_average(sub_list):
    # Returns an floating point value for the average of a list.

    int_list = [int(i) for i in sub_list] # converts strings to ints

    return sum(int_list) / len(int_list)
    
###############################################################################

file = open('High Word.txt')
input_string = file.read()
file.close()

mylist = input_string.split(',')

frames_per_row = 6 # 60 FPS is the frame rate Zelda II runs at.

# Creates an unique name for the file based on int frames_per_row.
filename = 'High Word Tabbed '
filename += str(frames_per_row)
filename += '.txt'

text_file = open(filename, 'w') # Opens text file for writing.

# Creates a header line for the file, adjusted for excel spacing.
header = str(frames_per_row)
header += ' FRAME COLUMNS'
header += frames_per_row * '\t'
header += '\t' + 'AVERAGE'
header += 2 * '\t' + 'PBAG CHANCE'
header += 2 * '\t' + 'FRAMES PAST'
header += 2 * '\t' + 'SECONDS ELAPSED'
header += '\n'
text_file.write(header)

for x in range(0, len(mylist)):
    
    if x % frames_per_row == 0 and x > 0:
        
        sub_list = mylist[x - frames_per_row:x]
        
        average = rolling_average(sub_list)
        
        percent = chance_converter(average)
        
        text_file.write('\t' + str(round(average, 2)))
        text_file.write(2 * '\t' + str(round(percent, 4)))
        text_file.write(2 * '\t' + str(x))
        text_file.write(2 * '\t' + str(round(x / 60, 2)) + '\n')
        
    text_file.write(mylist[x] + '\t')
    
text_file.close()