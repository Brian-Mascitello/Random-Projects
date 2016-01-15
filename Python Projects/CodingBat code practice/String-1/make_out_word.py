# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p129981
Info:       Given an "out" string length 4, such as "<<>>", and a word, return
    a new string where the word is in the middle of the out string, e.g.
    "<<word>>". 

    make_out_word('<<>>', 'Yay') → '<<Yay>>'
    make_out_word('<<>>', 'WooHoo') → '<<WooHoo>>'
    make_out_word('[[]]', 'word') → '[[word]]'
    
    def make_out_word(out, word):
"""

def make_out_word(out, word):
    # Returns a string with the word variable inbetween halves of the out var.

    return out[:2] + word + out[2:]
    
###############################################################################

"""
# Examples:

make_out_word('<<>>', 'Yay') → '<<Yay>>'
make_out_word('<<>>', 'WooHoo') → '<<WooHoo>>'
make_out_word('[[]]', 'word') → '[[word]]'
"""