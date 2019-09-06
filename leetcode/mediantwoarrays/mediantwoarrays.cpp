class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1, size2, size3;
        int index1, index2;
        
        size1 = nums1.size();
        size2 = nums2.size();
        size3 = size1 + size2;
        index1 = index2 = size3 / 2;
        if ((size3 % 2) == 0) {
            index2 = index1 - 1;
        }
        
        int i = 0;
        int j = 0;
        int mean1 = 0;
        int mean2 = 0;
        int count = 0;
        while (count <= index1) {
            if (i == size1) {
                mean1 = nums2[j];
                j++;
            } else if (j == size2) {
                mean1 = nums1[i];
                i++;
            } else if (nums1[i] < nums2[j]) {
                mean1 = nums1[i];
                i++;
            } else {
                mean1 = nums2[j];
                j++;
            }
            
            if (count == index2) {
                mean2 = mean1;
            }
            count++;
        }
        
        return (double(mean1) + double(mean2))/2; 
    }
};
