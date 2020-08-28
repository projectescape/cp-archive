int Solution::solve(vector<int> &A) {
    if (A.size() == 1) return A[0];
    if (A[1] < A[0]) return A[0];
    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
            return A[i];
        }
    }
    return A[A.size() - 1];
}
