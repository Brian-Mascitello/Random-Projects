# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/2/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p197466
Info:       Given an int n, return the absolute difference between n and 21,
    except return double the absolute difference if n is over 21. 

    diff21(19) → 2
    diff21(10) → 11
    diff21(21) → 0
    
    def diff21(n):
"""

def diff21(n):
    # Returns the absolute difference between n and 21, if n is greater than 21
    # return double the difference.
    
    if n <= 21:
        return abs(21 - n)
    
    return 2 * abs(21 - n)

###############################################################################

"""
# Test Cases

print(diff21(19)) # Should be 2
print(diff21(10)) # Should be 11
print(diff21(21)) # Should be 0
"""