class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 0:
            return
        for i in range(k):
            nums.insert(0, nums[-1])
            nums.pop()
        return