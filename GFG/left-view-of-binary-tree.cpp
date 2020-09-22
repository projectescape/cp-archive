void helper(Node *&curr, vector<int> &ans, int &d) {
    if (!curr) return;
    if (d > ans.size()) {
        ans.push_back(curr->data);
    }
    d++;
    helper(curr->left, ans, d);
    helper(curr->right, ans, d);
    d--;
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    int d = 1;
    helper(root, ans, d);
    return ans;
}