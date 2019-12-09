class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long mynum = num;
        if (mynum == 0) {
            return true;
        }
        for (unsigned long long i = 1 ; ; i++) {
            unsigned long long sq = i * i;
            if (sq == mynum) {
                return true;
            } else if (sq > mynum) {
                return false;
            }
        }        
    }
};
