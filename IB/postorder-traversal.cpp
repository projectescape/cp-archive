vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    stack<int> l;
    queue<TreeNode*> q;
    s.push(A);
    TreeNode* temp;
    while (!s.empty()) {
        if (!s.top()) {
            s.pop();
            ans.push_back(l.top());
            l.pop();
            continue;
        }
        temp = s.top();
        s.pop();
        l.push(temp->val);
        s.push(NULL);
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    return ans;
}
