class Solution {
public:
    string toHex(int num) {
        unsigned int mynum = num;
        string res;
        valarray<char> hex {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        if (mynum == 0) {
            return "0";
        } else if (mynum > 0) {
            while (mynum > 0) {
                int tmp;
                tmp = mynum%16;
                res += hex[tmp];
                mynum /= 16;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
