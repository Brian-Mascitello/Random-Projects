# -*- coding: utf-8 -*-
"""
Author: Brian Mascitello
Date:   12/15/2015
School: Arizona State University
Info:   This program will takes an integer as input, calculates the digit sum
    of the given number, determine the number's prime factorization, calculates
    the digit sum of the number's prime factorization, compare the two sums to 
    each other and determine if they are equivalent, and finally print the
    results to the screen.
Inspiration:	The YouTube video title = "4937775 - Numberphile" is linked below.
    http://www.youtube.com/watch?v=mlqAvhjxAjo
    A Smith Number is when both the digits of the original integer added
    together and the sum of the prime factorization of the number is equal. A
    Smith Number cannot be a prime number, which is divisible only by one and
    itself. My goal is to have the program determine entered numbers as Smith
    or not. This program should still show whether or not it is prime, as well
    as its factors, regardless of it being Smith or not.
Learned:
    How to unpack a multivariable return in python.
    
    # Create packed tuple.
    pair = ("dog", "cat")
    
    # Unpack tuple.
    (key, value) = pair
    
    # Display unpacked variables.
    print(key)
    print(value)
"""

import math
import sys
import time

def digit_sum(d):
    # Returns the digit sum of the input d.
    # 26 would return 8 since 2+6=8.

    sum = 0

    while d > 0:
        
        sum += d % 10
        d = math.floor(d / 10)
        
    return sum

def prime_factorization(p):
    # Finds the prime factorization of the input p and returns it in a tuple
    # with the sum of all the element placed in the prime factorization array.

    factorization_array = []
    index = 1
 
    for index in range (2, int(p / index)):
        
        while p % index == 0:
            factorization_array.append(index)
            p = int(p / index);
            
    if p > 1:
            
        factorization_array.append(p)
        
    if p == factorization_array[0]:
        factorization_array[0] = 1
        factorization_array.append(p)
        
    index = 0
    summation = 0
    
    for index in range (0, len(factorization_array)):
        if factorization_array[index] > 9:
            summation += digit_sum(factorization_array[index])
        else:
            summation += factorization_array[index]
            
    return (factorization_array, summation)
  
def smith_number(s):
    # Returns a string stating whether s is a Smith Number or not.

    constant = int(s) # If possible converts input s to integer.
    
    if constant < 4:
        return 'All integers less than four can not be a Smith Number.'
    else:
        smith_pair = prime_factorization(constant)
        (factorization, summation) = smith_pair
        
        if digit_sum(constant) == summation:
            return True
            
        return False

###############################################################################

start = time.time()

text_file = open("Smith Number Results.txt", "w")

text_file.write("64-bit Smith Numbers \n\n")

counter = 0

text_file.write("0 s:\t")

for x in range (4, sys.maxsize):
    
    if smith_number(x) == True:
        counter = counter + 1
        text_file.write(str(x) + ', ')
        
        if counter == 10:
            counter = 0
            text_file.write('\n')
            end = time.time()
            stop_time = math.floor(end - start)
            
            if stop_time > 600:
                break
            
            text_file.write(str(stop_time) + " s:\t")
    
text_file.close()