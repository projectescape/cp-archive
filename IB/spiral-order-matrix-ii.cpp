vector<vector<int>> Solution::generateMatrix(int A) {
    vector<vector<int>> ans(A, vector<int>(A, -1));
    int curr = 1;
    for (int i = 0; i < A && curr <= A * A; i++) {
        for (int j = i; j < A - i; j++) {
            ans[i][j] = curr++;
        }
        if (curr > A * A) break;
        for (int j = i + 1; j < A - i; j++) {
            ans[j][A - i - 1] = curr++;
        }
        if (curr > A * A) break;
        for (int j = A - i - 2; j >= i; j--) {
            ans[A - i - 1][j] = curr++;
        }
        if (curr > A * A) break;
        for (int j = A - i - 2; j > i; j--) {
            ans[j][i] = curr++;
        }
    }
    return ans;
}
