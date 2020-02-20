class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> mym(100);
        vector<int> res;
        int rownum {0};
        for (auto row: mat) {
            int cnt{0};
            for (auto col: row) {
                if (!col) {
                    break;
                }
                cnt++;
            }
            mym[cnt].push_back(rownum);
            rownum++;
        }
        int rescnt{0};
        while (rescnt < k) {
            for (auto row : mym) {
                if (rescnt >= k) {
                    break;
                }
                for (auto col: row) {
                    if (rescnt >= k) {
                        break;
                    }
                    res.push_back(col);
                    rescnt++;
                }
            }
        }
        return res;
    }
};
