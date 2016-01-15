# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://codingbat.com/prob/p132290
Info:       The web is built with HTML strings like "<i>Yay</i>" which draws
    Yay as italic text. In this example, the "i" tag makes <i> and </i> which
    surround the word "Yay". Given tag and word strings, create the HTML string
    with tags around the word, e.g. "<i>Yay</i>". 

    make_tags('i', 'Yay') → '<i>Yay</i>'
    make_tags('i', 'Hello') → '<i>Hello</i>'
    make_tags('cite', 'Yay') → '<cite>Yay</cite>'
    
    def make_tags(tag, word):
"""

def make_tags(tag, word):
    # Returns a string in HTML tag format.

    front_tag = '<' + tag + '>'
    hind_tag = '</' + tag + '>'
    
    return front_tag + word + hind_tag
    
###############################################################################

"""
# Examples:

make_tags('i', 'Yay') → '<i>Yay</i>'
make_tags('i', 'Hello') → '<i>Hello</i>'
make_tags('cite', 'Yay') → '<cite>Yay</cite>'
"""