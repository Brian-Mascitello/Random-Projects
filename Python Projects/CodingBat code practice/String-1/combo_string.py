# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       2/22/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p194053
Info:       Given 2 strings, a and b, return a string of the form
    short+long+short, with the shorter string on the outside and the longer
    string on the inside. The strings will not be the same length, but they may
    be empty (length 0). 

    combo_string('Hello', 'hi') → 'hiHellohi'
    combo_string('hi', 'Hello') → 'hiHellohi'
    combo_string('aaa', 'b') → 'baaab'
    
    def combo_string(a, b):
"""

def combo_string(a, b):
    """
    Combines strings a and b in the form aba or bab, where the middle of the
    new strings is the longer of the two inputs.
    """
    
    if (len(a) < len(b)):
        
        return a + b + a
        
    return b + a + b
    
###############################################################################

# Test Cases:

print(combo_string('Hello', 'hi')) # 'hiHellohi'
print(combo_string('hi', 'Hello')) # 'hiHellohi'
print(combo_string('aaa', 'b')) # 'baaab'