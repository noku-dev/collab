class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        """
        # Solution 1, convert to string
        if x < 0:
            return False
        s1 = str(x)
        l1 = len(s1)
        if l1 < 1:
            return False
        elif l1 < 2:
            return True
        # compare half
        lhalf = l1/2
        s2 = ''.join(reversed(s1))
        # s2 = s1[::-1]
        if s1[:lhalf] == s2[:lhalf]:
            return True
        return False
        """
        """
        # two one line solutions (from answers)
        return str(x) == str(x)[::-1]
        return False if x < 0 else x == int(str(x)[::-1])
        """
        # Solution 2, do not convert to string
        if x < 0:
            return False
        if x < 10:
            return True
        if x % 10 == 0:
            return False
        
        reverted = 0;
        while x > reverted:
            reverted = reverted * 10 + x % 10
            x /= 10

        return x == reverted or x == reverted/10
