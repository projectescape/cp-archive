vector<vector<int>> Solution::solve(int A) {
    vector<vector<int>> ans(A);
    if (A == 0) return ans;
    ans[0] = {1};
    if (A == 1) return ans;
    ans[1] = {1, 1};
    for (int i = 2; i < A; i++) {
        ans[i].push_back(1);
        for (int j = 1; j < ans[i - 1].size(); j++) {
            ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
        }
        ans[i].push_back(1);
    }
    return ans;
}
