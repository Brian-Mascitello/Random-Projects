# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/5/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p147920
Info:       Given a string, we'll say that the front is the first 3 chars of
    the string. If the string length is less than 3, the front is whatever is
    there. Return a new string which is 3 copies of the front. 

    front3('Java') → 'JavJavJav'
    front3('Chocolate') → 'ChoChoCho'
    front3('abc') → 'abcabcabc'
    
    def front3(str):
"""

def front3(str):
    # Returns 3 copies of the first 3 letters in str.

    return 3 * str[:3]
    
###############################################################################

"""
# Examples provided

front3('Java') → 'JavJavJav'
front3('Chocolate') → 'ChoChoCho'
front3('abc') → 'abcabcabc'
"""