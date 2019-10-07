int binSearch(int* nums, int low, int high, int target) {
    int mid = (low + high)/2;
    if (low >= high)
        return low;
    if (nums[mid] == target)
        return mid;
    if (nums[mid] < target)
        return binSearch(nums, mid + 1, high, target);
    if (nums[mid] > target)
        return binSearch(nums, low, high - 1, target);
    return mid;
}

int searchInsert(int* nums, int numsSize, int target){
    // brute force
    /*
    int i = 0;
    while (i < numsSize) {
        if (nums[i] >= target)
            return i;
        i++;
    }
    return i;
    */
    // binary search
    return binSearch(nums, 0, numsSize, target);
}
