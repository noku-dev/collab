class Solution {
public:
    // Decided to use a reverse iterator and process the roman numeral from right to left, made more sense to me, easier to handle
    // a case like IX or XL as in a reverse iteration we have seen the L (prev variable) before we see the X so we can decrement (50-10) 
    int romanToInt(string s) {
        int num {0};
        char prev{0};
        for (auto it = s.crbegin(); it != s.crend(); ++it) {
            switch (*it) {
                case 'I':
                    if (prev == 'V' || prev == 'X') {
                        num -= 1;
                    } else {
                        num += 1;
                    }
                    break;
                case 'V':
                    num += 5;
                    break;                
                case 'X':
                    if (prev == 'L' || prev == 'C') {
                        num -= 10;
                    } else {
                        num += 10;
                    }
                    break;                
                case 'L':
                    num += 50;
                    break;                
                case 'C':
                    if (prev == 'D' || prev == 'M') {
                        num -= 100;
                    } else {
                        num += 100;
                    }
                    break;                
                case 'D':
                    num += 500;
                    break;                
                case 'M':
                    num += 1000;
                    break;                
            }
            prev = *it;
        } 
        return num;               
    }
};
