void findMin(TreeNode *curr, int d, int &ans) {
    if (!curr) return;
    if (!curr->left && !curr->right) {
        ans = min(ans, d);
        return;
    }
    d++;
    findMin(curr->left, d, ans);
    findMin(curr->right, d, ans);
}

int Solution::minDepth(TreeNode *A) {
    int ans = INT_MAX;
    if (!A) return 0;
    findMin(A, 1, ans);
    return ans;
}