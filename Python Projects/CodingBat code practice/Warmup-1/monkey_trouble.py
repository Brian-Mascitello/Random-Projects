# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/2/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p120546
Info:       We have two monkeys, a and b, and the parameters a_smile and
    b_smile indicate if each is smiling. We are in trouble if they are both
    smiling or if neither of them is smiling. Return True if we are in trouble. 

    monkey_trouble(True, True) → True
    monkey_trouble(False, False) → True
    monkey_trouble(True, False) → False

    def monkey_trouble(a_smile, b_smile):
"""

def monkey_trouble(a_smile, b_smile):
    # Returns True if a_smile and b_smile are equivalent.

    if a_smile == b_smile:
            return True
    return False
    
###############################################################################

"""
# Test Cases

print(monkey_trouble(True, True)) # Should be True
print(monkey_trouble(False, False)) # Should be True
print(monkey_trouble(True, False)) # Should be False
print(monkey_trouble(False, True)) # Should be False
"""