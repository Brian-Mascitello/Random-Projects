# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/2/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p141905
Info:       Given two int values, return their sum. Unless the two values are
    the same, then return double their sum. 

    sum_double(1, 2) → 3
    sum_double(3, 2) → 5
    sum_double(2, 2) → 8
    
    def sum_double(a, b):
"""

def sum_double(a, b):
    # Returns sum if a is not b, otherwise return double their sum.
    
    sum = a + b    
    
    if a == b:
        return 2 * sum
        
    return sum

###############################################################################

"""
# Test Cases

print(sum_double(1, 2)) # Should be 3
print(sum_double(3, 2)) # Should be 5
print(sum_double(2, 2)) # Should be 8
"""