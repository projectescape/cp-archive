string Solution::longestCommonPrefix(vector<string> &A) {
    if (A.size() == 0) return "";
    string ans = A[0];
    int j = 0;
    for (int i = 1; i < A.size(); i++) {
        for (j = 0; j < ans.size() && j < A[i].size() && A[i][j] == ans[j]; j++)
            ;
        ans.erase(ans.begin() + j, ans.end());
    }
    return ans;
}
