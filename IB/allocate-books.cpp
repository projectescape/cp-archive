int Solution::books(vector<int> &C, int A) {
    if (C.size() < A) return -1;
    int e = 0, s = INT_MIN;

    for (auto i : C) {
        e += i;
        s = max(s, i);
    }
    long long ans = LLONG_MAX, i, j, k, m;
    for (; s <= e;) {
        m = (s + e) / 2;
        for (i = j = k = 0; i < C.size() && k < A; i++) {
            j += C[i];
            if (j > m) {
                i--;
                k++;
                j = 0;
            } else if (j == m) {
                k++;
                j = 0;
            }
        }
        if (k < A || (k == A && i == C.size())) {
            ans = min(ans, m);
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    if (ans == LLONG_MAX) return -1;
    return ans;
}
