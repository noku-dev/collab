class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int max = (2 << 30) - 1;
        int max_div10 = max / 10;
        int max_mod10 = max % 10;
        while (x != 0) {
            if ((abs(result) > max_div10) || 
                ((abs(result) == max_div10) && abs(x) % 10 > max_mod10))
                return 0;
            result = result*10 + x % 10;
            x = x / 10;
        }
        return result;
    }
};
