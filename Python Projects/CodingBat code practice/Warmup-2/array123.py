# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p193604
Info:       Given an array of ints, return True if .. 1, 2, 3, .. appears in
    the array somewhere. 

    array123([1, 1, 2, 3, 1]) → True
    array123([1, 1, 2, 4, 1]) → False
    array123([1, 1, 2, 1, 2, 3]) → True
    
    def array123(nums):
"""

def array123(nums):
    # Returns True if array contains 1, 2, 3 somewhere in it.

    for x in range(0, len(nums) - 2):
        
        if nums[x] == 1 and nums[x + 1] == 2 and nums[x + 2] == 3:
            
            return True
            
    return False
    
###############################################################################

"""
# Test cases:

print(array123([1, 1, 2, 3, 1])) # True
print(array123([1, 1, 2, 4, 1])) # False
print(array123([1, 1, 2, 1, 2, 3])) # True
"""