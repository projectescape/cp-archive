int Solution::maxProduct(const vector<int> &A) {
    vector<int> pos(A.size(), 1), neg(A.size(), 1);
    if (A[0] > 0) {
        pos[0] = A[0];
    } else if (A[0] < 0) {
        neg[0] = A[0];
    }
    int ans = A[0];
    for (int i = 1, a, b; i < A.size(); i++) {
        if (A[i] == 0) {
            ans = max(ans, 0);
            continue;
        }
        a = A[i] * pos[i - 1];
        b = A[i] * neg[i - 1];
        if (a > 0) {
            pos[i] = a;
            neg[i] = b;
        } else {
            neg[i] = a;
            pos[i] = b;
        }
        ans = max({ans, pos[i], neg[i]});
    }
    return ans;
}
