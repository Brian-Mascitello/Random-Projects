"""
Author:     Brian Mascitello
Date:       4/17/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p148661
Info:       Given an array of ints length 3, return an array with the elements "rotated left" so {1, 2, 3} yields
    {2, 3, 1}.

    rotate_left3([1, 2, 3]) → [2, 3, 1]
    rotate_left3([5, 11, 9]) → [11, 9, 5]
    rotate_left3([7, 0, 0]) → [0, 0, 7]

    def rotate_left3(nums):
"""


def rotate_left3(nums):
    # Shifts all of the elements in the array to the index on the left.

    first_index = nums[0]

    for integer in range(0, len(nums) - 1):
        nums[integer] = nums[integer + 1]

    nums[-1] = first_index

    return nums

########################################################################################################################

print(rotate_left3([1, 2, 3]))  # [2, 3, 1]
print(rotate_left3([5, 11, 9]))  # [11, 9, 5]
print(rotate_left3([7, 0, 0]))  # [0, 0, 7]

