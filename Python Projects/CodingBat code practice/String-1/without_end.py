# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       2/22/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p138533
Info:       Given a string, return a version without the first and last char,
    so "Hello" yields "ell". The string length will be at least 2. 

    without_end('Hello') → 'ell'
    without_end('java') → 'av'
    without_end('coding') → 'odin'
    
    def without_end(str):
"""

def without_end(str):
    """
    Removes the first and last char of str.
    """
    
    return str[1:-1]
    
###############################################################################

# Test Cases:

print(without_end('Hello')) # → 'ell'
print(without_end('java')) # → 'av'
print(without_end('coding')) # → 'odin'