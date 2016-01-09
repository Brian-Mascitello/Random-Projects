# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/8/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p166170
Info:       Given an array of ints, return the number of 9's in the array. 

    array_count9([1, 2, 9]) → 1
    array_count9([1, 9, 9]) → 2
    array_count9([1, 9, 9, 3, 9]) → 3
    
    def array_count9(nums):
"""

def array_count9(nums):
    # Returns an integer of the total number of 9s in the provided array.

    count = 0
    
    for x in range(0, len(nums)):
        
        if nums[x] == 9:
            
            count += 1
            
    return count
    
###############################################################################

"""
# Test cases:

print(array_count9([1, 2, 9])) # 1
print(array_count9([1, 9, 9])) # 2
print(array_count9([1, 9, 9, 3, 9])) # 3
"""