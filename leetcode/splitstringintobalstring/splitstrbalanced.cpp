class Solution {
public:
    int balancedStringSplit(string s) {
        int numbal{0};
        int nL{0};
        int nR{0};
        for (auto c : s) {
            switch(c) {
                case 'R':
                    nR++;
                    break;
                case 'L':
                    nL++;
                    break;
                default:
                    // Do nothing
                    break;
            }
            if (nR == nL && nR > 0) {
                numbal++;
                nL = nR = 0;
            }
        }
        return numbal;
    }
};
