# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p148853
Info:       Given a string, return a new string made of 3 copies of the last 2
    chars of the original string. The string length will be at least 2. 

    extra_end('Hello') → 'lololo'
    extra_end('ab') → 'ababab'
    extra_end('Hi') → 'HiHiHi'
    
    def extra_end(str):
"""

def extra_end(str):
    """
    Returns a string comprised of three copies of the final two elements of the
    input str.
    """
    
    return 3 * str[len(str) - 2:]
    
###############################################################################

"""
# Examples:

print(extra_end('Hello')) # 'lololo'
print(extra_end('ab')) # 'ababab'
print(extra_end('Hi')) # 'HiHiHi'
"""