vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    stack<int> s;
    queue<TreeNode*> q;
    q.push(A);
    if (!A) s.push(A->val);
    TreeNode* temp;
    while (!q.empty()) {
        if (!q.front()) {
            q.pop();
            continue;
        }
        temp = q.front();
        q.pop();
        q.push(temp->right);
        q.push(temp->left);
        s.push(temp->val);
    }
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}