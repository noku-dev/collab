class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double accum{0.0};
        double maxAv = numeric_limits<double>::lowest();
        for (int i = 0; i < nums.size(); i++) {
            accum += nums[i];
            if (i >= k - 1) {
                maxAv = max(maxAv, accum/k);
                accum -= nums[i + 1 - k];
            }
        }
        return maxAv;        
    }
};
