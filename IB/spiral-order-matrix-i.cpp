vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int t = 0, b = A.size() - 1, l = 0, r = A[0].size() - 1, i;
    vector<int> ans;
    while (t <= b && l <= r) {
        if (t <= b && l <= r) {
            for (i = l; i <= r; i++) {
                ans.push_back(A[t][i]);
            }
            t++;
        }
        if (t <= b && l <= r) {
            for (i = t; i <= b; i++) {
                ans.push_back(A[i][r]);
            }
            r--;
        }
        if (t <= b && l <= r) {
            for (i = r; i >= l; i--) {
                ans.push_back(A[b][i]);
            }
            b--;
        }
        if (t <= b && l <= r) {
            for (i = b; i >= t; i--) {
                ans.push_back(A[i][l]);
            }
            l++;
        }
    }
    return ans;
}