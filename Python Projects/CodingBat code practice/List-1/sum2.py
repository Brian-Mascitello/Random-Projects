"""
Author:     Brian Mascitello
Date:       4/17/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p192589
Info:       Given an array of ints, return the sum of the first 2 elements in the array. If the array length is less
    than 2, just sum up the elements that exist, returning 0 if the array is length 0.

    sum2([1, 2, 3]) → 3
    sum2([1, 1]) → 2
    sum2([1, 1, 1, 1]) → 2

    def sum2(nums):
"""


def sum2(nums):
    # Returns the sum of the first two indices of the nums array.

    if len(nums) == 0:
        return 0
    elif len(nums) == 1:
        return nums[0]
    else:
        return nums[0] + nums[1]

########################################################################################################################

print(sum2([1, 2, 3]))  # 3
print(sum2([1, 1]))  # 2
print(sum2([1, 1, 1, 1]))  # 2
