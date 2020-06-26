int Solution::findMinXor(vector<int> &A) {
    int ans = INT_MAX;
    sort(A.begin(), A.end());
    for (int i = 1, j; i < A.size(); i++)
        ans = min(ans, A[i] ^ A[i - 1]);
    return ans;
}
