int helper(Node *&root, int &ans) {
    if (!root) return 0;
    int l = helper(root->left, ans), r = helper(root->right, ans);
    ans = max(l + r + 1, ans);
    return max(l, r) + 1;
}

int diameter(Node *node) {
    int ans = 0;
    helper(node, ans);
    return ans;
}