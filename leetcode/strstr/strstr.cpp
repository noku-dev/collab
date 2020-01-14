class Solution {
public:
    int strStr(string haystack, string needle) {
        int ret {0};
        int j{0};
        int k{0};
        if (needle.size() == 0) return ret; // Return 0 if needle is empty
        for (int i = 0 ; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                for (j = 0, k = i; 
                     j < needle.size() && k < haystack.size(); j++, k++) {
                    if (haystack[k] != needle[j]) break;
                }
                if (j == needle.size()) return i;
            }
        }
        return -1;
    }
};
