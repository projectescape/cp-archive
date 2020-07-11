
void getSubset(vector<int> &v, int idx, vector<int> &A, int n, int B, vector<vector<int> > &globalBox) {
    if (B < 0)
        return;
    if (B == 0) {
        globalBox.push_back(v);
        return;
    }
    for (int i = idx; i < n; i++) {
        if (i == 0 || (i > 0 && A[i - 1] != A[i])) {
            v.push_back(A[i]);
            getSubset(v, i, A, n, B - A[i], globalBox);
            v.pop_back();
        }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<int> v;
    sort(A.begin(), A.end());
    vector<vector<int> > globalBox;
    getSubset(v, 0, A, A.size(), B, globalBox);
    v.clear();
    return globalBox;
}