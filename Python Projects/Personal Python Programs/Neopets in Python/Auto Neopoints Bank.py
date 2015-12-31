# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       12/31/2015
School:     Arizona State University
Info:       Just remade Auto Neopoints Bank for Python
"""

import math # for rounding up daily interest.
import sys # for sys.maxsize on my computer 9223372036854775807

def daily_interest_finder(balance, rate):
    """
    Will find the daily interest of neopoints available at the bank.
    This will return an integer value.
    """
    
    return math.ceil(balance * rate / 100 / 365)
    
def next_neopoint_per_day(balance, daily, rate):
    """
    Finds the required amount of neopoints necessary to increase the daily 
    interest by one.
    This will return an integer value.
    """
    
    return math.ceil(daily / rate * 100 * 365 - balance)

def rate_finder(balance):
    """
    Takes the balance and finds the account type they have and the interest
    percentage as well.
    Returns a string for account type and a float rate for the interest rate.
    """
    
    if 0 <= balance and balance < 1000:
        account = 'Junior Saver'
        rate = 4.5

    elif 1000 <= balance and balance < 2500:
        account = 'Neopian Student'
        rate = 5.5
    
    elif 2500 <= balance and balance < 5000:
        account = 'Bronze Saver'
        rate = 6.0
        
    elif 5000 <= balance and balance < 10000:
        account = 'Silver Saver'
        rate = 6.5

    elif 10000 <= balance and balance < 25000:
        account = 'Super Gold Plus'
        rate = 7.0

    elif 25000 <= balance and balance < 50000:
        account = 'Platinum Extra'
        rate = 7.5

    elif 50000 <= balance and balance < 75000:
        account = 'Double Platinum'
        rate = 8.0

    elif 75000 <= balance and balance < 100000:
        account = 'Triple Platinum'
        rate = 8.5;
	
    elif 100000 <= balance and balance < 250000:
        account = 'Diamond Deposit'
        rate = 9.0
        
    elif 250000 <= balance and balance < 500000:
        account = 'Diamond Deposit Plus'
        rate = 9.5
        
    elif 500000 <= balance and balance < 1000000:
        account = 'Diamond Deposit Gold'
        rate = 10.0
        
    elif 1000000 <= balance and balance < 2000000:
        account = 'Millionaire Platinum'
        rate = 10.5
        
    elif 2000000 <= balance and balance < 5000000:
        account = 'Millionaire Double Platinum'
        rate = 11.0
        
    elif 5000000 <= balance and balance < 7500000:
        account = 'Millionaire Mega-Platinum'
        rate = 11.5
        
    elif 7500000 <= balance and balance < 10000000:
        account = 'Neopian Mega-Riches'
        rate = 12.0
        
    elif 10000000 <= balance and balance < sys.maxsize:
        account = 'Ultimate Riches!'
        rate = 12.5
        
    return (account, rate)
    
def yearly_interest_finder(balance, rate):
    """
    Will find the yearly interest if the neopoints are collected each day from
    the bank. This will return an integer value.
    """
    
    return int(balance * rate / 100)
    
###############################################################################

print('\nWelcome to the Python Auto Neopoints Bank Calculator')

balance = int(input('Enter your current Neopoint balance: '))

account_pair = rate_finder(balance)
(account, rate) = account_pair

print('\nAccount Type: \t \t', account)

print('Current Balance: \t', balance, 'NP')

# Used str(rate) to better match the official Neopets layout online.
print('Interest Rate: \t \t ' + str(rate) + '% per year')

yearly_interest = yearly_interest_finder(balance, rate)

print('Yearly Interest: \t', yearly_interest, 'NP')

daily_interest = daily_interest_finder(balance, rate)

# Separated by a space since this is further down on the webpage.
print('\nDaily Interest: \t', daily_interest, 'NP')

plus_one = next_neopoint_per_day(balance, daily_interest, rate)
print('Next Neopoint/Day: \t~' + str(plus_one) + 'NP')


