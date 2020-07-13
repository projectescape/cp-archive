void dfs(TreeNode* curr, queue<TreeNode*>& q) {
    if (!curr) return;
    q.push(curr);
    dfs(curr->left, q);
    dfs(curr->right, q);
}

TreeNode* Solution::flatten(TreeNode* A) {
    queue<TreeNode*> q;
    dfs(A, q);
    q.push(NULL);
    TreeNode* temp;
    while (q.size() > 1) {
        temp = q.front();
        q.pop();
        temp->left = NULL;
        temp->right = q.front();
    }
    return A;
}