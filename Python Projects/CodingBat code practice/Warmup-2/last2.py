# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/7/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p145834
Info:       Given a string, return the count of the number of times that a
    substring length 2 appears in the string and also as the last 2 chars of
    the string, so "hixxxhi" yields 1 (we won't count the end substring). 

    last2('hixxhi') → 1
    last2('xaxxaxaxx') → 1
    last2('axxxaaxx') → 2
    
    def last2(str):
"""

def last2(str):
    # Returns an integer of the number of times the last two indices of str are
    # repeated within str, not including themselves.

    count = 0
    
    if len(str) >= 4:
        
        last_two_letters = str[len(str) - 2:]
        
        for x in range(0, len(str) - 2):
        
            if str[x] + str[x + 1] == last_two_letters:
                
                count += 1
                
    return count
    
###############################################################################

"""
# Test cases:

print(last2('123')) # Should be 0
print(last2('hixxhi'))
print(last2('xaxxaxaxx'))
print(last2('axxxaaxx'))
"""