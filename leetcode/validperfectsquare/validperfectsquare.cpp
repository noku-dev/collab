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

// Now with binary search
class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long long sq,mynum;
        unsigned long long l,r,mid;
        l = 1;
        r = mynum = num;
        do {
            mid = (l + r)/2;
            sq = mid * mid;
            if (sq == mynum) {
                return true;
            } else if (sq < mynum) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }    
        } while (l <= r);
        return false;
    }
};
