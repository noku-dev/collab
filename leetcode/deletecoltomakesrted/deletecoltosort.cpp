class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int deletions {0};
        int numstrings = A.size();
        int size_of_string = A[0].size();
        for (int i = 0 ; i < size_of_string; i++) {
            for (int j = 0; j < numstrings - 1; j++) {
                if (A[j][i] > A[j+1][i]) {
                    deletions++;
                    break;
                }
            }
        }
        return deletions;    
    }
};
