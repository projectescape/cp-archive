void sol(unordered_map<int, bool> &m, vector<int> &ans, int &A, int &curr, int &prev, int pos) {
    if (pos == A) {
        if (m.find(curr) == m.end()) {
            ans.push_back(curr);
            prev = curr;
            m[curr] = true;
        }
        return;
    }
    if (prev == curr) {
        if (m.find(curr ^ (1 << pos)) == m.end()) {
            curr = curr ^ (1 << pos);
        }
    }
    sol(m, ans, A, curr, prev, pos + 1);
}

vector<int> Solution::grayCode(int A) {
    int curr = 0, prev = 0;
    unordered_map<int, bool> m;
    vector<int> ans;
    ans.push_back(0);
    m[0] = true;
    while (ans.size() != pow(2, A))
        sol(m, ans, A, curr, prev, 0);
    return ans;
}
