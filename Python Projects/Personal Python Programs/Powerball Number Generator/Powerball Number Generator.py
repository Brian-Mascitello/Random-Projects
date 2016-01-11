# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/10/2016
School:     Arizona State University
Websites:   http://www.durangobill.com/PowerballOdds.html
Info:       Gives random numbers for the Powerball.
"""

import random

def random_ball_selector(start, end, quantity):
    """
    Generates a list of numbers from start to end inclusive and randomly
    selects 5 unique numbers to return as integers.
    """
    
    balls_list = list(range(start, end + 1))
    return_balls = []
    
    for i in range(0, quantity):
        
        new_number = random.choice(balls_list)
        
        return_balls.append(new_number)
        
        balls_list.remove(new_number)
        
    return sorted(return_balls)

###############################################################################

data = int(input('How many Powerball sets would you like to generate? '))

text = open('Random Powerball Numbers.txt', 'w')

for i in range(0, data):
    
    powerball_whites = random_ball_selector(1, 69, 5)
    powerball_red = random_ball_selector(1, 26, 1)
    
    whites_string = str(powerball_whites).replace('[','').replace(']','')
    whites_string = 'White Numbers: ' + whites_string
    
    red_string = str(powerball_red).replace('[','').replace(']','')
    red_string = '\t Powerball: ' + red_string
    
    text.write(whites_string + str(red_string))
    
    if i < data:
        text.write('\n')
    
text.close()
    