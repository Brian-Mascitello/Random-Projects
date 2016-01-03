# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/3/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p166884
Info:       We have a loud talking parrot. The "hour" parameter is the current
    hour time in the range 0..23. We are in trouble if the parrot is talking
    and the hour is before 7 or after 20. Return True if we are in trouble. 

    parrot_trouble(True, 6) → True
    parrot_trouble(True, 7) → False
    parrot_trouble(False, 6) → False
    
    def parrot_trouble(talking, hour):
"""

def parrot_trouble(talking, hour):
    # If talking is True and hour < 7 or hour > 20, return True for trouble.
    
    if talking:
        
        if hour < 7 or hour > 20:
            
            return True
        
    return False

###############################################################################

"""
# Test Cases

print(parrot_trouble(True, 6)) # Should be True
print(parrot_trouble(True, 7)) # Should be False
print(parrot_trouble(False, 6)) # Should be False
"""