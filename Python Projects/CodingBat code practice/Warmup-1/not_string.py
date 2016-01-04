# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/4/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p189441
Info:       Given a string, return a new string where "not " has been added to
    the front. However, if the string already begins with "not", return the
    string unchanged.

    not_string('candy') → 'not candy'
    not_string('x') → 'not x'
    not_string('not bad') → 'not bad'
    
    def not_string(str):
"""

def not_string(str):
    # Adds not to the front of a the string str if it doesn't already begin
    # with not.

    if str.startswith('not'):
        
        return str
        
    else:
        
        return 'not ' + str

###############################################################################

"""
# Examples provided:

not_string('candy') → 'not candy'
not_string('x') → 'not x'
not_string('not bad') → 'not bad'
"""