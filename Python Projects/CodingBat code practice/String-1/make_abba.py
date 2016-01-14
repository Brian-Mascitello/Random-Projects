# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p182144
Info:       Given two strings, a and b, return the result of putting them
    together in the order abba, e.g. "Hi" and "Bye" returns "HiByeByeHi". 

    make_abba('Hi', 'Bye') → 'HiByeByeHi'
    make_abba('Yo', 'Alice') → 'YoAliceAliceYo'
    make_abba('What', 'Up') → 'WhatUpUpWhat'
    
    def make_abba(a, b):
"""

def make_abba(a, b):
    # Returns a string made from the inputs in the form a + b + b + a.

    return a + b + b + a
    
###############################################################################

"""
# Examples:

make_abba('Hi', 'Bye') → 'HiByeByeHi'
make_abba('Yo', 'Alice') → 'YoAliceAliceYo'
make_abba('What', 'Up') → 'WhatUpUpWhat'
"""