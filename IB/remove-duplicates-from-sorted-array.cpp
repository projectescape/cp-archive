int Solution::removeDuplicates(vector<int> &A) {
    vector<int> ans;
    if (A.size() == 0) return 0;
    ans.push_back(A[0]);
    for (int i = 1; i < A.size(); i++) {
        if (A[i] == A[i - 1]) continue;
        ans.push_back(A[i]);
    }
    A = ans;
    return A.size();
}
