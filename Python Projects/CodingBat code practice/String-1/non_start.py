# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       2/22/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p127703
Info:       Given 2 strings, return their concatenation, except omit the first
    char of each. The strings will be at least length 1. 

    non_start('Hello', 'There') → 'ellohere'
    non_start('java', 'code') → 'avaode'
    non_start('shotl', 'java') → 'hotlava'
    
    def non_start(a, b):
"""

def non_start(a, b):
    """
    Concatenates string a and b, except without the first letter in each string.
    """
    
    return a[1:] + b[1:]
    
###############################################################################

# Test Cases:

print(non_start('Hello', 'There')) # 'ellohere'
print(non_start('java', 'code')) # 'avaode'
print(non_start('shotl', 'java')) # 'hotlava'