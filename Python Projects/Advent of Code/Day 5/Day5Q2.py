# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/22/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/5
            http://adventofcode.com/day/5/input
Info:       --- Part Two ---

    Realizing the error of his ways, Santa has switched to a better model of
    determining whether a string is naughty or nice. None of the old rules
    apply, as they are all clearly ridiculous.

    Now, a nice string is one with all of the following properties:

    - It contains a pair of any two letters that appears at least twice in the
    string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but not like
    aaa (aa, but it overlaps).
    - It contains at least one letter which repeats with exactly one letter
    between them, like xyx, abcdefeghi (efe), or even aaa.
    
    For example:

    - qjhvhtzxzqqjkmpb is nice because is has a pair that appears twice (qj)
    and a letter that repeats with exactly one letter between them (zxz).
    - xxyxx is nice because it has a pair that appears twice and a letter that
    repeats with one between, even though the letters used by each rule
    overlap.
    - uurcxstgmygtbstg is naughty because it has a pair (tg) but no repeat with
    a single letter between them.
    - ieodomkazucvgmuy is naughty because it has a repeating letter with one
    between (odo), but no pair that appears twice.
    
    How many strings are nice under these new rules?
"""

def letter_sandwich(word):
    # Returns True if word has a letter that repeats two indices away from it.
    
    if any(word[index] == word[index + 2] for index in range(len(word) - 2)):
        # As soon as it finds a True, exits and returns True.    
        
        return True
        
    else:
        
        return False
        
def repeat_pair(word):
    # Returns True if a pair of two letter occur at least twice in word.

    if any(word.count(word[index : index + 2]) > 1 for index in range(len(word) - 2)):
        # Counts the occurance of two letters in word, if more than 1, True.
        
        return True
        
    else:
        
        return False
        
###############################################################################

nice_strings_count = 0

with open('Day5Q1 Input.txt') as current:
    # Term "current" is the file that's opened.

    for line in current:
        # Goes through each line in the open file "current".
        
        if letter_sandwich(line) and repeat_pair(line):
            # If all True, the current string line is nice.
        
            nice_strings_count += 1
            
print('Number of nice strings:', nice_strings_count) # 238