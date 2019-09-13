class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int,int> mp;
        for (auto elem : A) {
            mp[elem]++;
            if (mp[elem] > 1) {
                return elem;
            }
        }
        return -1;
    }
};
