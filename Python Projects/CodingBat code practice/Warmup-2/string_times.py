# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/6/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p193507
Info:       Given a string and a non-negative int n, return a larger string
    that is n copies of the original string. 

    string_times('Hi', 2) → 'HiHi'
    string_times('Hi', 3) → 'HiHiHi'
    string_times('Hi', 1) → 'Hi'
    
    def string_times(str, n):
"""

def string_times(str, n):
    # If n is positive, return string str n times.

    return n * str
    
###############################################################################

"""
# Examples provided:

string_times('Hi', 2) → 'HiHi'
string_times('Hi', 3) → 'HiHiHi'
string_times('Hi', 1) → 'Hi'
"""