void helper(Node *&curr, map<int, pair<int, int>> &m, int d, int &l) {
    if (!curr) return;
    if (m.find(d) == m.end()) {
        m[d] = {curr->data, l};
    } else if (m[d].second <= l) {
        m[d] = {curr->data, l};
    }
    l++;
    helper(curr->left, m, d - 1, l);
    helper(curr->right, m, d + 1, l);
    l--;
}

vector<int> bottomView(Node *root) {
    int l = 0;
    map<int, pair<int, int>> m;
    helper(root, m, 0, l);
    vector<int> ans;

    for (auto &i : m) {
        ans.push_back(i.second.first);
    }
    return ans;
}