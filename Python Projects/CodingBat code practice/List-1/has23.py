"""
Author:     Brian Mascitello
Date:       4/17/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p177892
Info:       Given an int array length 2, return True if it contains a 2 or a 3.

    has23([2, 5]) → True
    has23([4, 3]) → True
    has23([4, 5]) → False
"""


def has23(nums):
    # If nums has a 2 or a 3 in it, return True.

    for x in range(0, len(nums)):
        if nums[x] == 2 or nums[x] == 3:
            return True

    return False

########################################################################################################################

print(has23([2, 5]))  # True
print(has23([4, 3]))  # True
print(has23([4, 5]))  # False
