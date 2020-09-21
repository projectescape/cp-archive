int helper(Node *&root, bool &ans) {
    if (!root) return 0;
    int l = helper(root->left, ans), r = helper(root->right, ans);
    if (abs(l - r) > 1) {
        ans = false;
    }
    return max(l, r) + 1;
}

bool isBalanced(Node *root) {
    bool ans = true;
    helper(root, ans);
    return ans;
}