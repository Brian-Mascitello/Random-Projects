# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       2/22/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p160545
Info:       Given a string, return a "rotated left 2" version where the first 2
    chars are moved to the end. The string length will be at least 2. 

    left2('Hello') → 'lloHe'
    left2('java') → 'vaja'
    left2('Hi') → 'Hi'
    
    def left2(str):
"""

def left2(str):
    """
    Moves the first two characters to the end of str.
    """
    
    return str[2:] + str[:2]
    
###############################################################################

# Test Cases:

print(left2('Hello')) # 'lloHe'
print(left2('java')) # 'vaja'
print(left2('Hi')) # 'Hi'