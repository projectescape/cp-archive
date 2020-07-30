vector<int> Solution::solve(vector<int> &A) {
    vector<int> ans;
    int curr = INT_MIN;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] > curr) {
            ans.push_back(A[i]);
            curr = A[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
