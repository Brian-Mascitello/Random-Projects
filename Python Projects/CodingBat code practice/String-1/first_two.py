# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/16/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p184816
Info:       Given a string, return the string made of its first two chars, so
    the String "Hello" yields "He". If the string is shorter than length 2,
    return whatever there is, so "X" yields "X", and the empty string "" yields
    the empty string "". 

    first_two('Hello') → 'He'
    first_two('abcdefg') → 'ab'
    first_two('ab') → 'ab'
    
    def first_two(str):
"""

def first_two(str):
    """
    Returns a string comprised of the first two indices of the input str.
    If str is length one, return itself.
    If str is empty, return ''.
    """
    
    if len(str) >= 2:
        
        return str[:2]
        
    elif len(str) == 1:
        
        return str
    
    elif len(str) == 0:
        
        return ''
    
###############################################################################

"""
# Test Cases:

print(first_two('Hello')) # → 'He'
print(first_two('abcdefg')) # → 'ab'
print(first_two('ab')) # → 'ab'
print(first_two('')) # → ''
"""
