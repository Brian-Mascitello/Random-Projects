# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/20/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/4
Info:       --- Day 4: The Ideal Stocking Stuffer ---

    Santa needs help mining some AdventCoins (very similar to bitcoins) to use
    as gifts for all the economically forward-thinking little girls and boys.

    To do this, he needs to find MD5 hashes which, in hexadecimal, start with
    at least five zeroes. The input to the MD5 hash is some secret key (your
    puzzle input, given below) followed by a number in decimal. To mine
    AdventCoins, you must find Santa the lowest positive number (no leading
    zeroes: 1, 2, 3, ...) that produces such a hash.

    For example:

    - If your secret key is abcdef, the answer is 609043, because the MD5 hash
    of abcdef609043 starts with five zeroes (000001dbbfa...), and it is the
    lowest such number to do so.
    - If your secret key is pqrstuv, the lowest number it combines with to make
    an MD5 hash starting with five zeroes is 1048970; that is, the MD5 hash of
    pqrstuv1048970 looks like 000006136ef....
    
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
        
        if hex_message[0:5] == '00000': # Compares indexes [0,4] in hex_message
            return i
            break
        
    return None
    
input = 'iwrupvqb' # My input from Advent of Code 2015

# print('abcdef =', md5_hash_in_hex('abcdef')) # Should be 609043
# print('pqrstuv =', md5_hash_in_hex('pqrstuv')) # Should be 1048970
print('puzzle input =', md5_hash_in_hex(input))