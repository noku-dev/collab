class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits {0};
        while (n > 0) {
            if (n & 1) bits++;
            n >>= 1;
        }
        return bits;
    }
};
