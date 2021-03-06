# -*- coding: utf-8 -*-
"""
Author: Brian Mascitello
Date:   12/16/2015
School: Arizona State University
Info:   Simple program for making a text file of primes that I can use later
    and optimize "Smith Number.py". Not the fastest but using the results for
    speeding up another program.
"""

import time

def prime_finder(termination_number):
    # Finds primes up to termination_number and saves them to a file.

    primes = [2, 3, 5] # Starts an array for storing & finding prime numbers.
    
    text_file = open("Prime Numbers 10M.txt", "w")
    text_file.write('2,3,5') # Writes the first three primes to file.

    for x in range(7, termination_number, 2):
        # Starts at 7, iterates to the termination_number only using odds.
        # This eliminated checking even numbers as >2 evens cannot be prime.
        # Removes 1/2 cases
    
        if x % 10 != 5:
            # Quick check to remove another 1/10 of the total cases.
            # All primes >5 cannot end in 5.
            
            for y in range(1, len(primes)):
                # Starts at index 1 since we know even numbers won't be here.
            
                if x % primes[y] == 0:
                    # x is divisible by a prime thus x itself is not prime.
                    break
                
                if x < primes[y] ** 2:
                    # Since this checks smallest divsors first, if a primes[y]
                    # is greater than sqrt(x), no need to check further.
                    # As right side increases, less iterations of loop, more
                    # time saved though less primes checked.
                
                    primes.append(x) # Includes new prime in array.
                    text_file.write(',' + str(x)) # Records prime in file.
                    break
            
    text_file.close()
                
    return primes

start = time.time()

# 1000000 takes ~ 6.5 seconds on my computer.
prime_finder(10000000) # Will find prime numbers up to 1000000.

end = time.time()

print(end - start)