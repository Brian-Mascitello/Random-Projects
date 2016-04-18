"""
Author:     Brian Mascitello
Date:       4/17/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p192962
Info:       Given an array of ints length 3, return a new array with the elements in reverse order, so {1, 2, 3} becomes
    {3, 2, 1}.

    reverse3([1, 2, 3]) → [3, 2, 1]
    reverse3([5, 11, 9]) → [9, 11, 5]
    reverse3([7, 0, 0]) → [0, 0, 7]

    def reverse3(nums):
"""


def reverse3(nums):
    # Returns the array nums in reverse order.

    return list(reversed(nums))

########################################################################################################################

print(reverse3([1, 2, 3]))  # [3, 2, 1]
print(reverse3([5, 11, 9]))  # [9, 11, 5]
print(reverse3([7, 0, 0]))  # [0, 0, 7]
