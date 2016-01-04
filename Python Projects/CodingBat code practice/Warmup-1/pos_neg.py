# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/4/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p162058
Info:       Given 2 int values, return True if one is negative and one is
    positive. Except if the parameter "negative" is True, then return True only
    if both are negative. 

    pos_neg(1, -1, False) → True
    pos_neg(-1, 1, False) → True
    pos_neg(-4, -5, True) → True

    def pos_neg(a, b, negative):
"""

def pos_neg(a, b, negative):
    # If negative is True, return True if both a and b are negative.
    # Otherwise return True if either a or b is postive, but not both.

    if negative:
        
        if a < 0 and b < 0:
            
            return True
                
    else:
        
        if a < 0 and b >= 0:
            
            return True
            
        elif a >= 0 and b < 0:
            
            return True
            
    return False

###############################################################################

"""
# Test Cases

print(pos_neg(1, -1, False)) # Should be True
print(pos_neg(-1, 1, False)) # Should be True
print(pos_neg(-4, -5, True)) # Should be True
"""