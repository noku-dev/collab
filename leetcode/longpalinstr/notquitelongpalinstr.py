class Solution(object):
    def checkPalindrome(self, subs):
        i = 0
        j = len(subs) - 1
        while (i < j):
            if (subs[i] != subs[j]):
                return False
            i = i + 1
            j = j - 1
        return True
    
    
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        longest = 0
        palindrome = ""
        if (len(s) > 0):
            longest = 1
            palindrome = s[0]
        for i in range(len(s)):
            j = len(s) - 1
            while (i != j):
                if (s[i] == s[j]):
                    if self.checkPalindrome(s[i:j+1]):
                        if longest < (j - i + 1):
                            longest = max(longest, j - i + 1)
                            palindrome = s[i:j+1]
                            break
                j = j - 1
                if longest > (j - i):
                    break
            if longest > (len(s) - i):
                break
        return palindrome
