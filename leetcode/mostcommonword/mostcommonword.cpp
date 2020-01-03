class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> b(banned.begin(), banned.end());
        string res, w;
        map<string,int> m;
        // Convert uppercase to lowercase and convert any non alpha character
        // e.g. a comma into spaces so they don't become part of the words 
        // when we extract words from the string stream
        for (char &c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }
        istringstream ss(paragraph);
        // Read word by word from string stream
        while (ss >> w) {
            // If word not in banned list, increase its count and update
            // res if necessary
            if (b.find(w) == b.end()) {
                m[w]++;
                if (m[res] < m[w]) {
                    res = w;
                }
            }
        }
        return res;
    }
};
