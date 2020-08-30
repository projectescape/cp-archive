int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int ans = INT_MAX;
    for (int i = 0, j = 0, k = 0; i < A.size() && j < B.size() && k < C.size();) {
        if (A[i] <= B[j] && A[i] <= C[k]) {
            ans = min(ans, max(B[j], C[k]) - A[i]);
            i++;
        } else if (B[j] <= A[i] && B[j] <= C[k]) {
            ans = min(ans, max(A[i], C[k]) - B[j]);
            j++;
        } else {
            ans = min(ans, max(A[i], B[j]) - C[k]);
            k++;
        }
    }
    return ans;
}