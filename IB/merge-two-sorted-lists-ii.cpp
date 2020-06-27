void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> ans(A.size() + B.size());
    for (int i = 0, j = 0, k = 0; i < A.size() || j < B.size(); k++) {
        if (i == A.size()) {
            ans[k] = B[j++];
        } else if (j == B.size()) {
            ans[k] = A[i++];
        } else if (A[i] < B[j]) {
            ans[k] = A[i++];
        } else {
            ans[k] = B[j++];
        }
    }
    A = ans;
}
