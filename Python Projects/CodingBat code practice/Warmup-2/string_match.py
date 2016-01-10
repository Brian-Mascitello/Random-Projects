# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p193604
Info:       Given 2 strings, a and b, return the number of the positions where
    they contain the same length 2 substring. So "xxcaazz" and "xxbaaz" yields
    3, since the "xx", "aa", and "az" substrings appear in the same place in
    both strings. 

    string_match('xxcaazz', 'xxbaaz') → 3
    string_match('abc', 'abc') → 2
    string_match('abc', 'axc') → 0
    
    def string_match(a, b):
"""

def string_match(a, b):
    """
    Returns an integer counting the number of length 2 substrings that are
    found at the same index in both strings a and b.
    """
    
    count = 0
    smallest = min(len(a), len(b))
    
    for x in range(smallest - 1):
        
        substr_a = a[x:x + 2]
        substr_b = b[x:x + 2]
        
        if substr_a == substr_b:
            
            count += 1
        
    return count
    
###############################################################################

"""
# Test cases:

print(string_match('xxcaazz', 'xxbaaz')) # 3
print(string_match('abc', 'abc')) # 2
print(string_match('abc', 'axc')) # 0
"""