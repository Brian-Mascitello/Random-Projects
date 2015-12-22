# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/21/2015
School:     Arizona State University
Websites:   http://adventofcode.com/day/5
            http://adventofcode.com/day/5/input
Info:       --- Day 5: Doesn't He Have Intern-Elves For This? ---

    Santa needs help figuring out which strings in his text file are naughty or
    nice.

    A nice string is one with all of the following properties:

    - It contains at least three vowels (aeiou only), like aei, xazegov, or
    aeiouaeiouaeiou.
    - It contains at least one letter that appears twice in a row, like xx,
    abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
    - It does not contain the strings ab, cd, pq, or xy, even if they are part
    of one of the other requirements.
    
    For example:

    - ugknbfddgicrmopn is nice because it has at least three vowels
    (u...i...o...), a double letter (...dd...), and none of the disallowed
    substrings.
    - aaa is nice because it has at least three vowels and a double letter,
    even though the letters used by different rules overlap.
    - jchzalrnumimnmhp is naughty because it has no double letter.
    - haegwjzuvuyypxyu is naughty because it contains the string xy.
    - dvszwmarrgswjxmb is naughty because it contains only one vowel.

    How many strings are nice?
"""

def bad_strings(word):
    # Returns False if word contains ab, cd, pq, or xy.

    for index in range(0, len(word) - 1):
        
        if word[index : index + 2] == 'ab':
            
            return False
            
        if word[index : index + 2] == 'cd':
            
            return False
            
        if word[index : index + 2] == 'pq':
            
            return False
            
        if word[index : index + 2] == 'xy':
            
            return False
            
    return True

def double_letter(word):
    # Returns True if word has a double letter like 'bb' or 'gg'.
    
    for index in range(0, len(word) - 1):
        
        if word[index] == word[index + 1]:
            
            return True
            
    return False
    
def three_vowels(word):
    # Returns True if word has at least three vowels in it.

    vowel_count = 0
    
    vowel_count += word.count('a') # Adds the number of a's to vowel_count
    vowel_count += word.count('e')
    vowel_count += word.count('i')
    vowel_count += word.count('o')
    vowel_count += word.count('u')
    
    # print(vowel_count)    
    
    if vowel_count > 2:
        
        return True
        
    else:
        
        return False   

###############################################################################

nice_strings_count = 0

with open('Day5Q1 Input.txt') as current:
    # Term "current" is the file that's opened.

    for line in current:
        # Goes through each line in the open file "current".
        
        if three_vowels(line) and double_letter(line) and bad_strings(line):
            # If all True, the current string line is nice.
        
            nice_strings_count += 1
            
print('Number of nice strings:', nice_strings_count) # 238