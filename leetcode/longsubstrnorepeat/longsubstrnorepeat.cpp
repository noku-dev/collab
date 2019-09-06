class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, longest;
        bool match = false;
        
        longest = 0;
        for (i = 0; i < s.length(); i++) {
            match = false;
            for (j = i + 1; j < s.length(); j++) {
                if (s.substr(i,j-i).find_first_of(s[j]) < (j - i)) {
                    longest = max(longest, j - i);
                    match = true;
                    break;
                }
            }
            if (!match) {
                longest = max(longest, j - i);
            }
        }
        return longest;
    }
};
