class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        int i;
        // Iterate over all numbers from left to right, included
        for (i = left ; i <= right ; i++) {
            int x = i;
            int digit;
            bool selfdiv = true;
            // Extract all digits from number
            while (x > 0) {
                // Extract last digit
                digit = x % 10;
                // shift number one decimal position to the right
                x /= 10;
                // if digit is 0 then divide by 0 error, if modulo has a remainder
                // then number cannot be divided by one of its digits, makes no sense
                // to continue, break and save time
                if (digit == 0 || i % digit != 0) {
                    selfdiv = false;
                    break;
                }
            }
            // If after checking all digits the number is still selfdivisible, add
            // it to our results
            if (selfdiv) {
                result.push_back(i);
            }
        }
        return result;
    }
};
