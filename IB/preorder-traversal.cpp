vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    if (A) s.push(A);
    TreeNode* temp;
    while (!s.empty()) {
        if (!s.top()) {
            s.pop();
            continue;
        }
        temp = s.top();
        s.pop();
        ans.push_back(temp->val);
        s.push(temp->right);
        s.push(temp->left);
    }
    return ans;
}