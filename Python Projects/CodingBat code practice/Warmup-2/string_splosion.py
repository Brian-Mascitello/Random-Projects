# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/6/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p118366
Info:       Given a non-empty string like "Code" return a string like "CCoCodCode". 

    string_splosion('Code') → 'CCoCodCode'
    string_splosion('abc') → 'aababc'
    string_splosion('ab') → 'aab'
    
    def string_splosion(str):
"""

def string_splosion(str):
    # Returns a string based off str.

    string = ''

    for x in range(0, len(str)):
        
        string += str[:x + 1]

    return string
    
###############################################################################

"""
# Test cases:

print(string_splosion('Code'))
print(string_splosion('abc'))
print(string_splosion('ab'))
"""