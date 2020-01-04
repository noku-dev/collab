class Solution {
public:
    int findComplement(int num) {
        unsigned int p = -1;
        int k = log2(num);
        p = p << k;
        p = ~p;
        unsigned int n = ~num;
        return (p & n);
    }
};
