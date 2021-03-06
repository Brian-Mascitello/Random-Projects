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

import math # Necessary for the floor function.

def digit_sum(d):
    # Returns the digit sum of the input d.
    # 26 would return 8 since 2+6=8.

    sum = 0 # Integer variable for storing the total sum of digits.

    while d > 0:
        # Takes the last digit of d and adds to sum, then divides by 10 to
        # remove the trailing digit.
        
        sum += d % 10
        d = math.floor(d / 10)
        
    return sum

def prime_factorization(p):
    # Finds the prime factorization of the input p and returns it in a tuple
    # with the sum of all the element placed in the prime factorization array.

    factorization_array = [] # Will store the integers of the prime
    # factorization and be returned.
    
    index = 1 # Sets to 1 since 0 is divide by zero error.
 
    for index in range (2, int(p / index)):
        # Goes from 2 (the first prime number) to p/index since you can not 
        # evenly divide a number greater than half of it other than by itself.
        # (say p = 211, since 211 is prime, there will not be a divisor found,
        # and this will check 2, 3, 4, ..., 103, 104, 105)
        
        while p % index == 0:
            # Accounts for cases like 12, where the prime factorization is 
            # 2*2*3=12, since 2 appears twice, this nested loop catches the 2
            # twice and the 3 once.
        
            factorization_array.append(index)
            p = int(p / index);
            
    if p > 1:
        # Any number left from the above nested loops greater than 1 is
        # appended to the end of factorization_array.
    
        factorization_array.append(p)
        
    if p == factorization_array[0]:
        # In the case where p is prime, like 7, modifies [7] to be [1, 7], so
        # p != summation since by definition a Smith Number is composite.
    
        factorization_array.insert(0, 1)
        
    index = 0 # Resets index to 0 and since it will be used to traverse array.
    summation = 0 # Stores the summation of the digits in factorization_array.
    
    for index in range (0, len(factorization_array)):
        # Iterates through all of factorization_array and calculates summation.
        
        if factorization_array[index] > 9:
            # If the index is more than a single digit, call the digit_sum
            # function to break it apart and add that result to summation.
        
            summation += digit_sum(factorization_array[index])
            
        else:
            # If the index was a single digit, just add it to summation.
        
            summation += factorization_array[index]
            
    return (factorization_array, summation) 
  
def smith_number(s):
    # Returns a string stating whether s is a Smith Number or not.

    constant = int(s) # If possible converts input s to integer.
    
    if constant < 4:
        # Catches all cases less than 4 since 4 is the first Smith Number.
    
        return 'All integers less than four cannot be a Smith Number.'
        
    else:
        # Entered when a possible Smith Number is found.
        
        # smith_pair is a variable that unpacks the return values of
        # prime_factorization(p) so they can be used outside of the tuple.
        smith_pair = prime_factorization(constant)
        (factorization, summation) = smith_pair
        
        if digit_sum(constant) == summation:
            # If True constant is a Smith Number and returns a joyous string.
        
            return 'Yes! ' + str(constant) + ' is a Smith Number!!!!!'
            
        return 'No!  ' + str(constant) + ' is NOT a Smith Number.'

###############################################################################

print(smith_number(4))
print(smith_number(7))
print(smith_number(8))
print(smith_number(11))
print(smith_number(22))
print(smith_number(4937774))