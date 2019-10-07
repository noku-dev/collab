class Solution(object):
    def binSearch(self, nums, low, high, target):
        mid = (low + high)/2
        if (low >= high):
            if (nums[low] < target):
                return low + 1
            return low
        if (nums[mid] == target):
            return mid
        if (nums[mid] > target):
            return self.binSearch(nums, low, mid - 1, target)
        if (nums[mid] < target):
            return self.binSearch(nums, mid + 1, high, target)
        return mid
        
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        """"
        # brute force
        for i in range(0, len(nums)):
            if (nums[i] >= target):
                return i;
        return len(nums)
        """
        # binary search
        return self.binSearch(nums, 0, len(nums)-1, target)
