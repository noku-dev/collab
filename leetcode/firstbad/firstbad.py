# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def binSearch(self, low, high):
        mid = (low + high)/2
        if (low >= high):
            return low
        if isBadVersion(mid):
            return self.binSearch(low, mid)
        else:
            return self.binSearch(mid + 1, high)
        return mid
    
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.binSearch(1, n)
