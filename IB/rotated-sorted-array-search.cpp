int Solution::search(const vector<int> &A, int B) {
    int s = 0, e = A.size() - 1, m;
    while (s <= e) {
        m = (s + e) / 2;
        if (B == A[m]) return m;
        if (B < A[m]) {
            if (A[s] < A[m]) {
                if (B >= A[s]) {
                    e = m - 1;
                } else {
                    s = m + 1;
                }
            } else {
                e = m - 1;
            }
        } else {
            if (A[m] <= A[e]) {
                if (B <= A[e]) {
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            } else {
                s = m + 1;
            }
        }
    }
    return -1;
}
