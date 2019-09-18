class Solution {
public:
    // Simple solution using sort. More complicated solution would involve iterating from both ends of the vector and then pre-pending the largest square to a list. That would be O(n)
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> sq;
        for (auto a : A) {
            sq.push_back( a * a);
        }
        sort(sq.begin(),sq.end());
        return sq;
    }
};
