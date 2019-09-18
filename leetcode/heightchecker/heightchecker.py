class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        sortHeights = sorted(heights)
        result = 0
        for i in range(len(heights)):
            if sortHeights[i] <> heights[i]:
                result += 1
        return result
