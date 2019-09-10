class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        # Solution 1 using extra memory
        numSet = set()
        for x in nums:
            if x in numSet:
                numSet.remove(x)
            else:
                numSet.add(x)
        return numSet.pop()
        """
        # Solution 2 
        if len(nums) < 2:
            return nums[0]
        nums.sort()
        for x in range(0, len(nums) - 2, 2):
            print(x, nums[x], nums[x+1])
            if nums[x] <> nums[x+1]:
                return nums[x]
        return nums[-1]    
