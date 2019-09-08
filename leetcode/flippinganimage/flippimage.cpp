class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        // This solution does the operations in the argument passed, in place
        // I am assuming this is desirable as the argument is passed by reference
        // instead of a const. Although on the other hand the function signature
        // returns a vector, so perhaps the intention was not to modify the argument
        for (auto & row : A) {
            auto n = row.size();
            // Reverse each row
            for (auto i = 0 ; i < n/2 ; i++) {
                swap(row[i], row[n - i - 1]);
            }
            // Flip each row
            // There might be a way to do it all in one loop, but this way, we
            // don't have to worry for swaps that don't touch the middle element,
            // for example 10100, in which the swap logic won't swap the 1 in the
            // middle, and therefore it would be an exception to flip the bits after
            // doing the swaps. It also clearly shows the reverse and flip portion of
            // the steps required
            for (auto & x : row) {
                x = !x;
            }
        }
        // return the modified vector
        return A;
    }
};
