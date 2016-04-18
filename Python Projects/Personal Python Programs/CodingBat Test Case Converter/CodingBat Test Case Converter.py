# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       2/22/2016
School:     Arizona State University
Info:       Converts the test cases from codingbat to python-print cases.
    (These are actually useful.)
"""

def string_converter(input_string):
    """
    Adds "print(" to the start of each line.
    Doubles all ")" that appear.
    Replaces "→" with "#"
    """
    
    import re
    
    return_string = re.sub(r'[^\x00-\x7F]+', '', input_string)
    
    return_string = 'print(' + return_string
    return_string = return_string.replace('\n', '\nprint(')
    return_string = return_string.replace(')', ')) #')
    return_string = return_string.replace('  ', ' ')
    
    return return_string
    
###############################################################################

file = open('Input Test Cases.txt')
input_string = file.read()
file.close()

text_file = open('Output Test Cases.txt', 'w')

text_file.write(string_converter(input_string))

text_file.close()