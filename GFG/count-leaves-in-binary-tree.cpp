void helper(Node*& root, int& ans) {
    if (!root) return;
    if (!root->left && !root->right) {
        ans++;
        return;
    }
    helper(root->left, ans);
    helper(root->right, ans);
}

int countLeaves(Node* root) {
    int ans = 0;
    if (!root) return ans;
    helper(root, ans);
    return ans;
}
