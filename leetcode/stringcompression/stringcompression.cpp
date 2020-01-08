class Solution {
public:
    int compress(vector<char>& chars) {
        int i {0};
        int count{0};
        int sz = chars.size();
        if (sz <= 1) return sz;
        for (int j = 1; j <= sz ; j++) {
            count++;
            if (j == sz || chars[j] != chars[j - 1]) {
                chars[i++] = chars[j - 1];
                if (count > 1) {
                    string num = to_string(count);
                    for (auto c: num) {
                        chars[i++] = c;
                    }
                }
                count = 0;
            }
        }
        return i;          
    }
};
