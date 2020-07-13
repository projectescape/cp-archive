void inorder(TreeNode* curr, vector<int>& ans) {
    if (!curr) return;
    inorder(curr->left, ans);
    ans.push_back(curr->val);
    inorder(curr->right, ans);
}

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    inorder(A, ans);
    return ans;
}