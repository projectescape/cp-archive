int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        for (; i < A.size() - 1 && A[i] == A[i + 1]; i++)
            ;
        if (A.size() - i - 1 == A[i]) return 1;
    }
    return -1;
}
