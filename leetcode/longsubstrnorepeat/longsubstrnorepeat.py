class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        j = 1
        if len(s) == 0:
            return 0
        thislist = list(s[0])
        longest = len(thislist)
        for j in s[1:]:
            longest = max(longest, len(thislist))
            while j in thislist:
                thislist.pop(0)
            thislist.append(j)
        longest = max(longest, len(thislist))
        return longest
