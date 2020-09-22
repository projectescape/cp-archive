int helper(Node*& root, int& ans) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;
    if (!root->left) return helper(root->right, ans) + root->data;
    if (!root->right) return helper(root->left, ans) + root->data;
    int l = helper(root->left, ans), r = helper(root->right, ans);
    ans = max(ans, l + r + root->data);
    return max(l, r) + root->data;
}

int maxPathSum(Node* root) {
    int ans = INT_MIN;
    helper(root, ans);
    return ans;
}