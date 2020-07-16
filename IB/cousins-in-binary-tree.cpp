vector<int> Solution::solve(TreeNode *A, int B) {
    vector<int> ans;
    if (!A || A->val == B) return ans;
    queue<TreeNode *> q;
    q.push(A);
    q.push(NULL);
    TreeNode *temp;
    bool flag = false;
    while (!q.empty()) {
        if (!q.front()) {
            if (q.size() == 1) break;
            q.pop();
            q.push(NULL);
            if (flag) {
                while (q.front()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            continue;
        }
        temp = q.front();
        q.pop();
        if ((temp->left && temp->left->val == B) || (temp->right && temp->right->val == B)) {
            flag = true;
            continue;
        }
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    return ans;
}