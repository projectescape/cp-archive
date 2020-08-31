int Solution::maxArea(vector<int> &A) {
    if (A.size() < 2) return 0;
    int ans = A.size();
    for (int i = 0, j = A.size() - 1; i < j;) {
        ans = max(ans, min(A[i], A[j]) * (j - i));
        if (A[i] < A[j])
            i++;
        else
            j--;
    }
    return ans;
}
