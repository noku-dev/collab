class Solution(object):
    def checkPalindrome(self, s, i1, i2):
        while (i1 >= 0 and i2 < len(s) and s[i1] == s[i2]):
            i1 = i1 - 1
            i2 = i2 + 1
        return i2 - i1 - 1
        
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) < 1:
            return ""
        if len(s) == 1:
            return s
        
        start = 0
        end = 0
        for i in range(len(s)-1):
            # check odd first
            length = self.checkPalindrome(s, i+1, i+1)
            if (length > end - start + 1):
                start = i + 1 - length/2
                end = i + 1 + length/2
                # check even
            length = self.checkPalindrome(s, i, i+1)
            if (length > end - start + 1):
                start = i + 1 - length/2
                end = i + length/2
                
        return s[start:end+1]
