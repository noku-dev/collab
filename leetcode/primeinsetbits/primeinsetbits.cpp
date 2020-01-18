class Solution {
public:
    bool isPrime(int n) {
        bool prime{false};
        switch (n) {
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
            case 23:
            case 29:
            case 31:
                prime = true;
                break;
        }
        return prime;
    }
    int countBits(int n) {
        unsigned int un = n;
        int cnt{0};
        while (un > 0) {
            if (un & 1) {
                cnt++;
            }
            un >>= 1;
        }
        return cnt;
    }
    
    int countPrimeSetBits(int L, int R) {
        int count{0};
        for (int n = L; n <= R; n++) {
            if (isPrime(countBits(n))) {
                count++;
            }
        }
        return count;
    }
};
