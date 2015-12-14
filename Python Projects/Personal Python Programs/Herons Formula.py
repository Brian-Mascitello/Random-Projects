# -*- coding: utf-8 -*-
"""
Author: Brian Mascitello
Date:   12/13/2015
School: Arizona State University
Info:   Made one of my favorite math functions into a program.
"""

from math import sqrt

def herons_formula(a, b, c):
    # Finds the area of a triangle given the length of each of the three sides.

    semiperimeter = (a + b + c) / 2
    area = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c))
    
    return area
    
print("The area of a 3:4:5 triangle is " + str(herons_formula(3, 4, 5)) + " square units.")
print("The area of a 6:8:11 triangle is " + str(herons_formula(6, 8, 11)) + " square units.")
print("The area of a 22:74:90 triangle is " + str(herons_formula(22, 74, 90)) + " square units.")