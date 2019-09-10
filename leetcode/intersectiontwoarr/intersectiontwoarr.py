class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        len1 = len(nums1)
        len2 = len(nums2)
        result = list()
        if len1 == 0 or len2 == 0:
            return result
        nums1.sort()
        nums2.sort()
        i = 0
        j = 0
        while j < len(nums2):
            while i < len(nums1) and nums1[i] < nums2[j]:
                i += 1
            if i == len(nums1):
                break
            while j < len(nums2) and nums1[i] > nums2[j]:
                j += 1
            if j == len(nums2):
                break
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1
                j += 1
        return result
