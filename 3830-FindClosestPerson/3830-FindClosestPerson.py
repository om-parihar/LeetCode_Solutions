# Last updated: 7/25/2026, 10:56:16 PM
class Solution(object):
    def findClosest(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: int
        """
        disx=abs(x-z)
        disy=abs(y-z)
        if(disx==disy):
            return 0
        if(disx>disy):
            return 2
        else:
            return 1
        