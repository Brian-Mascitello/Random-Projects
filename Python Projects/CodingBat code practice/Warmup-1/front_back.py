# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/5/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p153599
Info:       Given a string, return a new string where the first and last chars
    have been exchanged. 

    front_back('code') → 'eodc'
    front_back('a') → 'a'
    front_back('ab') → 'ba'
    
    def front_back(str):
"""

def front_back(str):
    # Returns a string where the first and last indices have been swapped.

    if len(str) < 2:
        
        return str
        
    first = str[0]
    last = str[len(str) - 1]
    
    if len(str) == 2:
        
        return last + first
    
    else:
    
        middle = str[1:-1]
    
        return last + middle + first
    
###############################################################################

"""
# Test Cases

print(front_back('code')) # Should be eodc
print(front_back('a')) # Should be a
print(front_back('ab')) # Should be ba
"""