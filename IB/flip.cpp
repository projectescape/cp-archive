vector<int> Solution::flip(string A) {
    vector<int> v(A.size());
    for (int i = 0; i < A.size(); i++) {
        v[i] = A[i] == '1' ? -1 : 1;
    }
    int ans = 0;
    for (int i = 1; i < A.size(); i++) {
        v[i] = max(v[i], v[i] + v[i - 1]);
        if (v[i] > v[ans]) ans = i;
    }
    if (v[ans] < 1) return {};
    int j = ans;

    while (v[j] > 1 || (j - 1 >= 0 && v[j - 1] >= 0)) {
        j--;
    }
    return {j + 1, ans + 1};
}