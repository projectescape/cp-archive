void dfs(TreeNode* curr, int h, int& d) {
    if (!curr) return;
    d = max(d, h);
    dfs(curr->left, h + 1, d);
    dfs(curr->right, h + 1, d);
}

int Solution::maxDepth(TreeNode* A) {
    int depth = 0;
    dfs(A, 1, depth);
    return depth;
}