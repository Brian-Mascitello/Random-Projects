# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p115413
Info:       Given a string name, e.g. "Bob", return a greeting of the form
    "Hello Bob!". 

    hello_name('Bob') → 'Hello Bob!'
    hello_name('Alice') → 'Hello Alice!'
    hello_name('X') → 'Hello X!'
    
    def hello_name(name):
"""

def hello_name(name):
    # Returns a string that says hello to input name.

    return 'Hello ' + str(name) + '!'
    
###############################################################################

"""
# Examples:

hello_name('Bob') → 'Hello Bob!'
hello_name('Alice') → 'Hello Alice!'
hello_name('X') → 'Hello X!'
"""