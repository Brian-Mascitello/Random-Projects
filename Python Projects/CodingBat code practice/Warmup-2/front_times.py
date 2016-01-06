# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/6/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p165097
Info:       Given a string and a non-negative int n, we'll say that the front
    of the string is the first 3 chars, or whatever is there if the string is
    less than length 3. Return n copies of the front; 

    front_times('Chocolate', 2) → 'ChoCho'
    front_times('Chocolate', 3) → 'ChoChoCho'
    front_times('Abc', 3) → 'AbcAbcAbc'
    
    def front_times(str, n):
"""

def front_times(str, n):
    # Returns n copies of the first 3 letters in str.

    return n * str[:3]
    
###############################################################################

"""
# Examples provided:

front_times('Chocolate', 2) → 'ChoCho'
front_times('Chocolate', 3) → 'ChoChoCho'
front_times('Abc', 3) → 'AbcAbcAbc'
"""