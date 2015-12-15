# Brian Mascitello
# Arizona State University
# SoDA Club: Software Developers Association
# 9/10/2015
# These are my attempts at the Fibonacci sequence.

from math import sqrt
import time

def fibonacci_even_odd_recursive(n):
    # Recursion but with improved cases for even or odd n values.
    # It is necessary to have three n values defined for this function to work properly.

    if n < 2:
        return n
    elif n == 2:
        return 1
    else:
        if n % 2 == 0: # Even function if 0, odd if 1.
            return fibonacci_even_odd_recursive((n / 2) + 1) ** 2 - fibonacci_even_odd_recursive((n / 2) - 1) ** 2
        else:
            return fibonacci_even_odd_recursive((n - 1) / 2) ** 2 + fibonacci_even_odd_recursive((n + 1) / 2) ** 2

def fibonacci_golden_ratio(n):
    # Applies the explicit mathematical expression to solve for n.

    return ((1 + sqrt(5)) ** n - (1 - sqrt(5)) ** n) / (2 ** n * sqrt(5))

def fibonacci_iterative(n):
    # For-loop implementation rather than slower recursion.

    if n < 2:
        return n
    else:
        x = 0
        y = 1
        for i in range(0, n):
            temp = x
            x = y
            y = temp + y
        return x

fib_stored_values = {} # required for memoization in function "fibonacci_memoized(n)"
def fibonacci_memoized(n):
    # Uses a hash table to store previously calculated values, and references the hash before doing harder work.

    if n in fib_stored_values:
        return fib_stored_values[n]
    else:
        if n < 2:
            fib_stored_values[n] = n
        else:
            fib_stored_values[n] = fibonacci_memoized(n - 1) + fibonacci_memoized(n - 2)
        return fib_stored_values[n]

def fibonacci_recursive_plain(n):
    # The standard, reliable, yet slowest recursive method that solves Fibonacci.

    if n < 2:
        return n
    else:
        return fibonacci_recursive_plain(n - 1) + fibonacci_recursive_plain(n - 2)

fib_stored_values_two = {} # required for memoization in function "fibonacci_soda_special(n)"
def fibonacci_soda_special(n):
    # Attempt to improve the memoized version in this program by combining it with the even-odd function.
    # Generally slower, perhaps there is a problem with the method and the hash table.

    if n in fib_stored_values_two:
        return fib_stored_values_two[n]
    else:
        if n < 2:
            fib_stored_values_two[n] = n
        elif n == 2:
            fib_stored_values_two[n] = 1
        else:
            if n % 2 == 0: # Even function if 0, odd if 1.
                fib_stored_values_two[n] = fibonacci_even_odd_recursive((n / 2) + 1) ** 2 - fibonacci_even_odd_recursive((n / 2) - 1) ** 2
            else:
                fib_stored_values_two[n] = fibonacci_even_odd_recursive((n - 1) / 2) ** 2 + fibonacci_even_odd_recursive((n + 1) / 2) ** 2
        return fib_stored_values_two[n]

text_file = open("Fibonacci Results.txt", "w")

n = 30
text_file.write("Even Odd Recursive Fibonacci\n")
start = time.time()
for n in range(0, n):
    text_file.write(str(round(fibonacci_even_odd_recursive(n)))+"\n")
end = time.time()
text_file.write(str(end - start) + " seconds\n\n")
print("Even Odd:     " + str(end - start) + " seconds");

n = 30
text_file.write("Golden Ratio Fibonacci\n")
start = time.time()
for n in range(0, n):
    text_file.write(str(round(fibonacci_golden_ratio(n)))+"\n")
end = time.time()
text_file.write(str(end - start) + " seconds\n\n")
print("Golden Ratio: " + str(end - start) + " seconds");

n = 30
text_file.write("SoDA Special Fibonacci\n")
start = time.time()
for n in range(0, n):
    text_file.write(str(fibonacci_soda_special(n))+"\n")
end = time.time()
text_file.write(str(end - start) + " seconds\n\n")
print("SoDA Special: " + str(end - start) + " seconds");

n = 30
text_file.write("Iterative Fibonacci\n")
start = time.time()
for n in range(0, n):
    text_file.write(str(fibonacci_iterative(n))+"\n")
end = time.time()
text_file.write(str(end - start) + " seconds\n\n")
print("Iterative:    " + str(end - start) + " seconds");

n = 30
text_file.write("Memoized Fibonacci\n")
start = time.time()
for n in range(0, n):
    text_file.write(str(fibonacci_memoized(n))+"\n")
end = time.time()
text_file.write(str(end - start) + " seconds\n\n")
print("Memoized:     " + str(end - start) + " seconds");

n = 30
text_file.write("Recursive Fibonacci\n")
start = time.time()
for n in range(0, n):
    text_file.write(str(fibonacci_recursive_plain(n))+"\n")
end = time.time()
text_file.write(str(end - start) + " seconds")
print("Recursive:    " + str(end - start) + " seconds");

text_file.close()