class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        """
        nums3 = list()
        nums3.extend(nums1)
        nums3.extend(nums2)
        nums3.sort()
        length = len(nums3)
        if (length % 2) == 0:
            mean = nums3[length / 2] + nums3[(length / 2) - 1]
            return float(mean) / 2
        else:
            return nums3[length / 2]
        """
        len1 = len(nums1)
        len2 = len(nums2)
        len3 = len1 + len2
        even = False
        mean_index1 = len3 / 2 + 1
        if (len3 % 2) == 0:
            even = True
            mean_index2 = (len3 / 2)

        mean_value1 = 0
        mean_value2 = 0
        i = 0
        j = 0
        count = 0
        while (count < mean_index1):
            if i == len1:
                val = nums2[j]
                j = j + 1
            elif j == len2:
                val = nums1[i]
                i = i + 1
            elif nums1[i] <= nums2[j]:
                val = nums1[i]
                i = i + 1
            else:
                val = nums2[j]
                j = j + 1
            count = count + 1
            
            if even and count == mean_index2:
                mean_value2 = val
            elif count == mean_index1:
                mean_value1 = val
                
        if even:
            return float(mean_value1 + mean_value2) / 2
        return mean_value1
