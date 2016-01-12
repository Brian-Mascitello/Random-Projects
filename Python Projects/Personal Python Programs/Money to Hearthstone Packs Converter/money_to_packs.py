# -*- coding: utf-8 -*-
"""
Author:     Brian Mascitello
Date:       1/9/2016
School:     Arizona State University
Websites:   http://hearthstone.gamepedia.com/Card_pack
Info:       Younger brother wanted to see the most efficient way to buy 
    Hearthstone packs with money.
"""

def money_to_packs(funds):
    """
    Returns an integer value that is the maximum number of packs you could
    buy with the dollars you spend.
    """
    
    dollars = funds
    packs = 0
    
    while dollars - 3 >= 0:
        
        if dollars - 70 >= 0:
            
            packs += 60
            
            dollars -= 70
            
        elif dollars - 50 >= 0:
            
            packs += 40
            
            dollars -= 50
            
        elif dollars - 20 >= 0:
            
            packs += 15
            
            dollars -= 20
            
        elif dollars - 10 >= 0:
            
            packs += 7
            
            dollars -= 10
            
        else:
            
            packs += 2
            
            dollars -= 3
            
    return (dollars, funds, packs)
    
###############################################################################

(dollars, funds, packs) = money_to_packs(100)
print('If you spend $' + str(funds) + ' on packs, you would get ' + str(packs)
    + ' packs and have $' + str(dollars) + ' remaining.')
    
(dollars, funds, packs) = money_to_packs(652.32)
print('If you spend $' + str(funds) + ' on packs, you would get ' + str(packs)
    + ' packs and have $' + str(round(dollars, 2)) + ' remaining.')