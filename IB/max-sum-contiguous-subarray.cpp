int Solution::maxSubArray(const vector<int> &A) {
    if (A.size() == 0) return 0;
    vector<int> prefix(A.size());
    int ans = prefix[0] = A[0];
    for (int i = 1; i < A.size(); i++) {
        prefix[i] = max(prefix[i - 1] + A[i], A[i]);
        ans = max(ans, prefix[i]);
    }
    return ans;
}