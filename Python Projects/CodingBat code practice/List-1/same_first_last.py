"""
Author:     Brian Mascitello
Date:       4/17/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p179078
Info:       Given an array of ints, return True if the array is length 1 or more, and the first element and the last
    element are equal.

    same_first_last([1, 2, 3]) → False
    same_first_last([1, 2, 3, 1]) → True
    same_first_last([1, 2, 1]) → True

    def same_first_last(nums):
"""


def same_first_last(nums):
    # Returns True if array is nonempty and first index is equal to the last index.

    if len(nums) > 0 and nums[0] == nums[-1]:
        return True
    return False

########################################################################################################################

print(same_first_last([1, 2, 3]))  # False
print(same_first_last([1, 2, 3, 1]))  # True
print(same_first_last([1, 2, 1]))  # True
