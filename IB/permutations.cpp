void perm(vector<int> &a, vector<vector<int>> &ans, int pos) {
    if (pos == a.size()) {
        ans.push_back(a);
        return;
    }
    for (int i = pos; i < a.size(); i++) {
        swap(a[pos], a[i]);
        perm(a, ans, pos + 1);
        swap(a[pos], a[i]);
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    perm(A, ans, 0);
    return ans;
}
