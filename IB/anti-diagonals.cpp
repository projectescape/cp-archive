vector<vector<int>> Solution::diagonal(vector<vector<int>> &A) {
    vector<vector<int>> ans;
    int j, k;
    for (int i = 0; i < A[0].size(); i++) {
        ans.push_back({});
        j = 0, k = i;
        while (j < A.size() && k >= 0) {
            ans[ans.size() - 1].push_back(A[j++][k--]);
        }
    }
    for (int i = 1; i < A.size(); i++) {
        ans.push_back({});
        j = i, k = A[0].size() - 1;
        while (j < A.size() && k >= 0) {
            ans[ans.size() - 1].push_back(A[j++][k--]);
        }
    }
    return ans;
}
