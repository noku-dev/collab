class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        multiset<int> kset; // Multiset allows for repeated numbers
        if (k == 0) {
            return {};
        }
        // Fill up the multiset with the first k numbers
        for (int i = 0; i < k; i++) {
            kset.insert(nums[i]);
        }
        // Find the last element (multiset is ordered, so it'll be the largest)
        result.push_back(*kset.rbegin());
        // Loop for the rest of nums and keep removing the element left behind in the sliding
        // window and adding the next element on the sliding window and find the largest through rbegin
        for (int j = k ; j < nums.size(); j++) {
            kset.erase(kset.find(nums[j - k]));
            kset.insert(nums[j]);
            result.push_back(*kset.rbegin());
        }
        return result;        
    }
};
