# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/20/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/4
Info:       --- Part Two ---

    Now find one that starts with six zeroes.
    
    Your puzzle input is iwrupvqb.
"""

import hashlib # https://docs.python.org/2/library/hashlib.html

def md5_hash_in_hex(key):
    """
        Converts utf message to a bytes message. Then converts the bytes
        message to a md5 message, and finally to a hex format. Then checks to
        ensure the first 5 digits of the hex message are '00000', otherwise
        continues searching.
    """
    
    for i in range(10000000): # Used 10000000 since max in example is 1048970
        
        utf_message = key + str(i)
        
        # MD5 operates on bytes, so you have to encode Unicode string into
        # bytes, with line.encode('utf-8').
        byte_message = bytes(utf_message, 'utf-8')
        
        md5_message = hashlib.md5(byte_message)
        
        hex_message = md5_message.hexdigest()
        
        if hex_message[0:6] == '000000': # Compares index [0,5] in hex_message
            return i
            break
        
    return None
    
input = 'iwrupvqb' # My input from Advent of Code 2015

# print('abcdef =', md5_hash_in_hex('abcdef')) # Should be 609043
# print('pqrstuv =', md5_hash_in_hex('pqrstuv')) # Should be 1048970
print('puzzle input =', md5_hash_in_hex(input))