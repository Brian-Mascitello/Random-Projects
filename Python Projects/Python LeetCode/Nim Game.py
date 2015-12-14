# Name:     Brian Mascitello
# Date:     12/11/2015
# School:   Arizona State University
# URL:      https://leetcode.com/problems/nim-game/

class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
    
        # You lose if the number of stones is a multiple of four.
        return n % 4 != 0
