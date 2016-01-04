# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/4/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p149524
Info:       Given a non-empty string and an int n, return a new string where
    the char at index n has been removed. The value of n will be a valid index
    of a char in the original string (i.e. n will be in the range 0..len(str)-1
    inclusive). 

    missing_char('kitten', 1) → 'ktten'
    missing_char('kitten', 0) → 'itten'
    missing_char('kitten', 4) → 'kittn'
    
    def missing_char(str, n):
"""

def missing_char(str, n):
    # Remove the character in string str at location n.
    # Returns the remaining string.

    return str.replace(str[n], '')    
    
###############################################################################

"""
# Test Cases

print(missing_char('kitten', 1)) # Should be ktten
print(missing_char('kitten', 0)) # Should be itten
print(missing_char('kitten', 4)) # Should be kittn
"""