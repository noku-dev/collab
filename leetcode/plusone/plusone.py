class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits[-1] += 1
        i = len(digits) - 1
        while digits[i]/10 == 1:
            digits[i] = 0
            if i < 1:
                digits.insert(0,1)
            else:
                digits[i - 1] += 1
            i -= 1
        return digits
