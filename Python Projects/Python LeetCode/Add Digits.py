# Name:     Brian Mascitello
# Date:     12/11/2015
# School:   Arizona State University
# URL:      https://leetcode.com/problems/add-digits/

class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """

        if num < 10:
            return num

        """
        Implemented the digital root function from the hints found at
        https://en.wikipedia.org/wiki/Digital_root
        Also Vedic Squares are interesting.
        https://en.wikipedia.org/wiki/Vedic_square
        """

        # Forced digital_root to nearest int.
        return int(num - 9 * math.floor((num - 1) / 9))
