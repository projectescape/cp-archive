bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> v;
    for (int i = 0; i < A.size(); i++) {
        v.push_back({A[i], B[i]});
    }
    sort(v.begin(), v.end(), comp);
    vector<int> ans(A.size(), -1);
    for (int i = 0, j = 0; i < A.size(); i++) {
        for (j = 0; v[i].second > 0; j++) {
            if (ans[j] == -1) {
                v[i].second--;
            }
        }
        for (; ans[j] != -1; j++)
            ;
        ans[j] = v[i].first;
    }
    return ans;
}

// Gives TLE in interviwbit, but is enough as can't remember segment tree implementation in interview