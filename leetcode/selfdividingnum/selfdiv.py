class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        result = list()
        for i in range(left, right+1):
            num = i
            while num % 10 <> 0:
                if i % (num % 10) == 0:
                    num /= 10
                else:
                    break
            if num == 0:
                result.append(i)
            
        return result
