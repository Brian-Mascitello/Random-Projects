# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/6/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p113152
Info:       Given a string, return a new string made of every other char
    starting with the first, so "Hello" yields "Hlo". 

    string_bits('Hello') → 'Hlo'
    string_bits('Hi') → 'H'
    string_bits('Heeololeo') → 'Hello'
    
    def string_bits(str):
"""

def string_bits(str):
    # Returns a string comprised of each even index {0,2,4...} of str.

    string = ''

    for x in range(0, len(str), 2):
        
        string += str[x]

    return string
    
###############################################################################

"""
# Test cases:
print(string_bits('Hello'))
print(string_bits('Hi'))
print(string_bits('Heeololeo'))
"""