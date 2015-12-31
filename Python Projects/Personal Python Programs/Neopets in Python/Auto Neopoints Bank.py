# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/30/2015
School:     Arizona State University
Info:       Just remade Auto Neopoints Bank for Python
"""

def rate_finder(balance):
    """
    Takes the balance and finds the account type they have and the interest
    percentage as well.
    """
    
    if 0 <= balance and balance < 1000:
        print('\nAccount Type: \t \t Junior Saver')
        rate = 4.5

    elif 1000 <= balance and balance < 2500:
        print('\nAccount Type: \t \t Neopian Student')
        rate= 5.5
    
    elif 2500 <= balance and balance < 5000:
        print('\nAccount Type: \t \t Bronze Saver')
        rate = 6.0
        
    elif 5000 <= balance and balance < 10000:
        print('\nAccount Type: \t \t Silver Saver')
        rate = 6.5

    elif 10000 <= balance and balance < 25000:
        print('\nAccount Type: \t \t Super Gold Plus')
        rate = 7.0

    elif 25000 <= balance and balance < 50000:
        print('\nAccount Type: \t \t Platinum Extra')
        rate = 7.5

    elif 50000 <= balance and balance < 75000:
        print('\nAccount Type: \t \t Double Platinum')
        rate = 8.0

    elif 75000 <= balance and balance < 100000:
        print('\nAccount Type: \t \t Triple Platinum')
        rate = 8.5;
	
    elif 100000 <= balance and balance < 250000:
        print('\nAccount Type: \t \t Diamond Deposit')
        rate = 9.0
        
    elif 250000 <= balance and balance < 500000:
        print('\nAccount Type: \t \t Diamond Deposit Plus')
        rate = 9.5
        
    elif 500000 <= balance and balance < 1000000:
        print('\nAccount Type: \t \t Diamond Deposit Gold')
        rate = 10.0
        
    elif 1000000 <= balance and balance < 2000000:
        print('\nAccount Type: \t \t Millionaire Platinum')
        rate = 10.5
        
    elif 2000000 <= balance and balance < 5000000:
        print('\nAccount Type: \t \t Millionaire Double Platinum')
        rate = 11.0
        
    elif 5000000 <= balance and balance < 7500000:
        print('\nAccount Type: \t \t Millionaire Mega-Platinum')
        rate = 11.5
        
    elif 7500000 <= balance and balance < 10000000:
        print('\nAccount Type: \t \t Neopian Mega-Riches')
        rate = 12.0
        
    elif 10000000 <= balance and balance < 2147483647:
        print('\nAccount Type: \t \t Ultimate Riches!')
        rate = 12.5;    
    
###############################################################################

print('Welcome to the Python Auto Neopoints Bank Calculator')

balance = int(input("Enter your current Neopoint balance: "))

rate_finder(balance)