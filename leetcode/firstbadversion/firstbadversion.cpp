// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left {1};
        int right {n};
        while (left < right) {
            int middle = left + (right - left)/2;
            if (isBadVersion(middle)) {
                right = middle;
            } else {
                left = middle;
            }
            if ((right - left) == 1) {
                return isBadVersion(left)? left:right;
            }
        }
        return left;
    }
};
