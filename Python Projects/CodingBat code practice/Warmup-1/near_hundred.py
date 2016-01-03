# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/3/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p124676
Info:       Given an int n, return True if it is within 10 of 100 or 200. Note:
    abs(num) computes the absolute value of a number. 

    near_hundred(93) → True
    near_hundred(90) → True
    near_hundred(89) → False
    
    def near_hundred(n):
"""

def near_hundred(n):
    # Returns True if n is between 90 and 110 or 190 and 210.

    if abs(100 - n) <= 10 or abs(200 - n) <= 10:
        
        return True
        
    return False

###############################################################################

"""
# Test Cases

print(near_hundred(93)) # Should be True
print(near_hundred(90)) # Should be True
print(near_hundred(89)) # Should be False
"""