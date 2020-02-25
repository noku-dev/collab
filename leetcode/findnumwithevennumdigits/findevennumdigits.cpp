class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evencnt{0};
        string strnum;
        for (auto n : nums) {
            strnum = to_string(n);
            if (strnum.size() % 2 == 0) {
                evencnt++;
            }
        }
        return evencnt;
    }
};
