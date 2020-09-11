void helper(Node*& curr, vector<int>& v) {
    if (!curr) return;
    helper(curr->left, v);
    v.push_back(curr->data);
    helper(curr->right, v);
}

bool isBST(Node* root) {
    vector<int> v;
    helper(root, v);
    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= v[i - 1]) return false;
    }
    return true;
}