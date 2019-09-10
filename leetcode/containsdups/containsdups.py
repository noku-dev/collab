class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        setNums = set()
        if len(nums) < 2:
            return False
        for x in nums:
            if x in setNums:
                return True
            setNums.add(x)
        return False
