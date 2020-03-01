class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n, vector<int>(m,0));
        int cnt{0};
        for (auto i : indices) {
            for (int j = 0; j < m; j++) {
                matrix[i[0]][j]++;
            }
            for (int k = 0; k < n; k++) {
                matrix[k][i[1]]++;
            }
        }
        for (auto r : matrix) {
            for (auto c : r) {
                if (c % 2 != 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
