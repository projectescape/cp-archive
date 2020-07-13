TreeNode* Solution::invertTree(TreeNode* A) {
    if (!A) return A;
    swap(A->left, A->right);
    invertTree(A->left);
    invertTree(A->right);
    return A;
}