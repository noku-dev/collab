class Solution {
public:
    // Simple Euclidian gcd algorithm 
    int gcd(int a, int b) {
        while (b > 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    string gcdOfStrings(string str1, string str2) {
        // Taking advantage of knowledge that a compliant set of strings are 
        // based on repeating the same substring, so appending the strings in any 
        // order should give the same result, strings that are not "dividable"
        // won't have this commutative property
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        // The dividing substring has to be of length equivalent to 
        // the greatest common
        // divisor of the lengths of both strings
        int g = gcd(str1.size(), str2.size());
        // Get the slice "substring" which will be our answer
        return str1.substr(0,g);
    }
};
