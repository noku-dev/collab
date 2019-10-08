class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = str()
        if n == 1:
            return "1"
        prev = self.countAndSay(n - 1)
        # print(n, prev)
        val = prev[0]
        count = 0
        for i in prev:
            if i == val:
                count += 1
                # print(n, val, count)
            else:
                result += str(count)
                result += val
                count = 1
                val = i
                # print(n, val, count, prev)
        # print("end of for loop, result is ", result)
        result += str(count)
        result += val
        # print("after join, result is ", result)
        return result
