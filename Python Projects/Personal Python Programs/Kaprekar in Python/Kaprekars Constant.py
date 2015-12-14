# -*- coding: utf-8 -*-
"""
Author: Brian Mascitello
Date:   12/14/2015
School: Arizona State University
Info:   6174 is known as Kaprekar's constant, this program is going to test how
    many steps each number from [1000,9999] to reach Kaprekar's constant.
    More info @ https://en.wikipedia.org/wiki/6174_(number)
"""

import math # Necessary for the floor function.

def kaprekars_constant(k):
    # Returns a string showing the steps and the iteration count to 6174.
        
    constant = int(k) # If possible converts input k to integer.
    
    if constant < 1000 or constant > 9999:
        # Integer k is not four digits long and the function exits.
    
        return 'Input must be four digits long.'
        
    else:
        # Input k is four digits long.
    
        start = constant # Sets 'start' equal to the integer constant so constant can be maintained.
        number_array = [] # Creates an empty array that will be used for sorting the digits of start.
        
        for x in range (0, 4):
            # Indexes number_array from 0 to 3 inclusive.
        
            number_array.append(start % 10)
            start = math.floor(start / 10)
        
        if number_array[0] == number_array[1] and number_array[1] == number_array[2] and number_array[2] == number_array[3]:
            # Exits the function if all four digits of number_array are the same.
            # This case would give 0000 repeatedly if not handled.
            
            return str(constant) + ' is a repdigit.'
            
        else:
            current = constant # Sets 'current' equal to the integer constant so constant can be maintained.
            number_array.sort() # Sorts number_array in ascending order.
            return_string = "" # Used for concatenating the string for the return.
            steps = 0 # Integer steps will be used to count the iterations necessary to reach 6174.
            
            if current != 6174:
                
                return_string += str(constant) + ' -> '
                
                while True:
                    # Makes steps towards Kaprekar's constant by subtracting ascending from descending.
                    
                    steps += 1 
                    
                    ascending = number_array[0] * 1000 + number_array[1] * 100 + number_array[2] * 10 + number_array[3]
                    descending = number_array[3] * 1000 + number_array[2] * 100 + number_array[1] * 10 + number_array[0]
                    
                    current = descending - ascending # current = the next step in the solution towards Kaprekar's constant.
                    
                    if current == 6174:
                        # Exits the while loop if current is the goal.
                        break
                    
                    return_string += str(current) + ' -> '
                    
                    number_array = [] # Clears the number_array since append just adds to the end of arrays.
                    
                    for x in range (0, 4):
                        # Indexes number_array from 0 to 3 inclusive just like before.
                        
                        number_array.append(current % 10)
                        current = math.floor(current / 10)
                        
                    number_array.sort()
            
            return_string += str(current) + ' in ' + str(steps) + ' iterations.' # Finalizes the return_string.
    
    return return_string

###############################################################################

text_file = open("Kaprekar Results", "w")

text_file.write("Kaprekar's Calculations from 1000 to 9999\n")

for four_digits in range (1000, 10000):
    text_file.write(kaprekars_constant(four_digits)+"\n")
    
text_file.close()