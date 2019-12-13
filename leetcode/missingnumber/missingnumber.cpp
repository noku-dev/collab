class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = size*(size + 1)/2;
        int partsum {0};
        for (auto n : nums) {
            partsum += n;
        }
        return (sum - partsum);        
    }
};
