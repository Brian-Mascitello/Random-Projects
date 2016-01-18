# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/17/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p107010
Info:       Given a string of even length, return the first half. So the string
    "WooHoo" yields "Woo". 

    first_half('WooHoo') → 'Woo'
    first_half('HelloThere') → 'Hello'
    first_half('abcdef') → 'abc'
    
    def first_half(str):
"""

def first_half(str):
    """
    Returns the first half of str.
    """
    
    half_str = len(str) / 2
    
    return str[:half_str]
    
###############################################################################

"""
# Test Cases:

print(first_half('WooHoo')) # → 'Woo'
print(first_half('HelloThere')) # → 'Hello'
print(first_half('abcdef')) # → 'abc'
"""
