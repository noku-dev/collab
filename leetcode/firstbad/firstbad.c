// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int binSearch(low, high) {
    int mid = (int)(((long)low + (long)high)/2);
    if (low >= high)
        return low;
    if (isBadVersion(mid)) {
        return binSearch(low, mid);
    } else {
        return binSearch(mid+1, high);
    }
    return mid;
}

int firstBadVersion(int n) {
    return binSearch(1, n);
}
