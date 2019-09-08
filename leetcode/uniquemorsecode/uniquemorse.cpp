class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // Create set to store one entry per unique transformation
        set <string> transformations;
        vector <string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // iterate over all input words
        for (auto w : words) {
            // Create string to store our transformation, which is initialized as
            // empty, guaranteed by C++ standard
            string tran;
            // Iterate over all characters in the word
            for (auto c : w) {
                // Find the morse string by calculating the offset from character a to
                // the character in auto variable c, e.g. if c == 'a' then we retrieve
                // morse['a' - 'a'] which is morse[0], e.g. ".-" and concatenating
                // all the morse strings corresponding to the characters in the word
                tran += morse[c - 'a'];
            }
            transformations.insert(tran);
        }
        return transformations.size();
    }
};
