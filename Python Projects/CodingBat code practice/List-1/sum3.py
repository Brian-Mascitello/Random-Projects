"""
Author:     Brian Mascitello
Date:       4/17/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p191645
Info:       Given an array of ints length 3, return the sum of all the elements.

    sum3([1, 2, 3]) → 6
    sum3([5, 11, 2]) → 18
    sum3([7, 0, 0]) → 7

    def sum3(nums):
"""


def sum3(nums):
    # Returns the summation of the array.

    return sum(nums)

########################################################################################################################

print(sum3([1, 2, 3]))  # 6
print(sum3([5, 11, 2]))  # 18
print(sum3([7, 0, 0]))  # 7
