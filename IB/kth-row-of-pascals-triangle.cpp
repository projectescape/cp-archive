vector<int> Solution::getRow(int A) {
    if (A == 0) return {1};
    vector<vector<int>> ans(A + 1);
    ans[0] = {1};
    ans[1] = {1, 1};
    for (int i = 2; i < A + 1; i++) {
        ans[i].push_back(1);
        for (int j = 1; j < ans[i - 1].size(); j++) {
            ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
        }
        ans[i].push_back(1);
    }
    return ans[A];
}