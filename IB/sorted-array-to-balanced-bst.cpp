TreeNode* helper(const vector<int>& A, int s, int e) {
    if (s > e) return NULL;
    int m = (s + e) / 2;
    TreeNode* ans = new TreeNode(A[m]);
    ans->left = helper(A, s, m - 1);
    ans->right = helper(A, m + 1, e);
    return ans;
}

TreeNode* Solution::sortedArrayToBST(const vector<int>& A) {
    int m = A.size() / 2;
    TreeNode* ans = new TreeNode(A[m]);
    ans->left = helper(A, 0, m - 1);
    ans->right = helper(A, m + 1, A.size() - 1);
    return ans;
}