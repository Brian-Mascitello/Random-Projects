# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/3/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p124984
Info:       Given 2 ints, a and b, return True if one if them is 10 or if their
    sum is 10. 

    makes10(9, 10) → True
    makes10(9, 9) → False
    makes10(1, 9) → True
    
    def makes10(a, b):
"""

def makes10(a, b):
    # Returns True if a = 10, b = 10, or a + b = 10.

    if a == 10 or b == 10 or a + b == 10:
        
        return True
        
    return False

###############################################################################

"""
# Test Cases

print(makes10(9, 10)) # Should be True
print(makes10(9, 9)) # Should be False
print(makes10(1, 9)) # Should be True
"""