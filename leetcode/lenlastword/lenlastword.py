class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        prev_count = 0
        if len(s) < 1:
            return count
        for let in s:
            if let == ' ':
                if count <> 0:
                    prev_count = count
                count = 0
            else:
                count += 1

        if count == 0:
            return prev_count
        return count
