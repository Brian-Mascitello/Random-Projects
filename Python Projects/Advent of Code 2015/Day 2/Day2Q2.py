# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/19/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/2
            http://adventofcode.com/day/2/input   
Info:       --- Part Two ---

    The elves are also running low on ribbon. Ribbon is all the same width, so
    they only have to worry about the length they need to order, which they
    would again like to be exact.

    The ribbon required to wrap a present is the shortest distance around its
    sides, or the smallest perimeter of any one face. Each present also
    requires a bow made out of ribbon as well; the feet of ribbon required for
    the perfect bow is equal to the cubic feet of volume of the present. Don't
    ask how they tie the bow, though; they'll never tell.

    For example:
    
    - A present with dimensions 2x3x4 requires 2+2+3+3 = 10 feet of ribbon to
    wrap the present plus 2*3*4 = 24 feet of ribbon for the bow, for a total
    of 34 feet.
    - A present with dimensions 1x1x10 requires 1+1+1+1 = 4 feet of ribbon to
    wrap the present plus 1*1*10 = 10 feet of ribbon for the bow, for a total
    of 14 feet.
    
    How many total feet of ribbon should they order?
"""

dimensions_array = []
total_paper_needed = 0;
total_ribbon_needed = 0;

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
        # These are areas and are not meant for ribbon.
        smallest = dimensions_array[0] * dimensions_array[1]
        medium = dimensions_array[0] * dimensions_array[2]
        largest = dimensions_array[1] * dimensions_array[2]
        
        # Adds the surface area plus an extra smallest side for slack.
        total_paper_needed += 3 * smallest + 2 * medium + 2 * largest
        
        # Finds the variables for calculating the ribbon.
        smallest_perimeter = 2 * (dimensions_array[0] + dimensions_array[1])
        bow = dimensions_array[0] * dimensions_array[1] * dimensions_array[2]
        
        # Adds the smallest two side lengths twice and the ribbon for bow.
        total_ribbon_needed += smallest_perimeter + bow
        
# print(dimensions_array) # Used to test array, final one should be [5, 11, 23]
print(total_paper_needed) # Total square feet of wrapping paper needed.
print(total_ribbon_needed) # Total feet of ribbon needed.