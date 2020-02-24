class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string lkey;
        int cnt{0};
        for (auto rit = S.crbegin(); rit != S.crend(); rit++) {
            if (*rit == '-') continue;
            if ((cnt % K) == 0) {
                // Insert dash every K chars
                lkey += "-";
            }
            lkey += toupper(*rit);
            cnt++;
        }
        // Erase first dash
        lkey.erase(0,1);
        reverse(lkey.begin(), lkey.end());
        return lkey;
    }
};
