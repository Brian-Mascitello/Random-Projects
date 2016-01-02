# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/1/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p173401
Info:       The parameter weekday is True if it is a weekday, and the parameter
    vacation is True if we are on vacation. We sleep in if it is not a weekday
    or we're on vacation. Return True if we sleep in. 

    sleep_in(False, False) → True
    sleep_in(True, False) → False
    sleep_in(False, True) → True
    
    def sleep_in(weekday, vacation):
"""

def sleep_in(weekday, vacation):
    # Returns True if weekday is False or if vacation is True.

    if weekday:
        if not vacation:
            return False
    return True
    
###############################################################################

"""
Test Cases

print(sleep_in(False, False)) # Should be True
print(sleep_in(True, False)) # Should be False
print(sleep_in(False, True)) # Should be True
print(sleep_in(True, True)) # Should be True
"""