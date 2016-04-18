"""
Author:     Brian Mascitello
Date:       4/17/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p135290
Info:       Given an array of ints length 3, figure out which is larger between the first and last elements in the
    array, and set all the other elements to be that value. Return the changed array.

    max_end3([1, 2, 3]) → [3, 3, 3]
    max_end3([11, 5, 9]) → [11, 11, 11]
    max_end3([2, 11, 3]) → [3, 3, 3]
"""


def max_end3(nums):
    # Returns the nums array filled solely with the greater of either the first or last integer.

    if nums[0] > nums[-1]:
        for value in range(0, len(nums)):
            nums[value] = nums[0]
    else:
        for value in range(0, len(nums)):
            nums[value] = nums[-1]

    return nums

########################################################################################################################

print(max_end3([1, 2, 3]))  # [3, 3, 3]
print(max_end3([11, 5, 9]))  # [11, 11, 11]
print(max_end3([2, 11, 3]))  # [3, 3, 3]
