class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(1,1);
        if (rowIndex <= 0) return result;
        result.push_back(1);
        if (rowIndex == 1) return result;
        for (int i = 2; i <= rowIndex; i++) {
            vector<int> tmp(result.size() + 1, 1);
            for (int j = 1; j < result.size(); j++) {
                tmp[j] = result[j] + result[j - 1];
            }
            result = tmp;
        }
        return result;        
    }
};
