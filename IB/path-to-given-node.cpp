bool path(TreeNode *curr, int &num, vector<int> &ans) {
    if (!curr) return false;
    if (curr->val == num || path(curr->left, num, ans) || path(curr->right, num, ans)) {
        ans.push_back(curr->val);
        return true;
    }
    return false;
}

vector<int> Solution::solve(TreeNode *A, int B) {
    vector<int> ans;
    path(A, B, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}