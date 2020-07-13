bool sol(TreeNode* curr, int& num, int& ans) {
    if (num == 0) return true;
    if (curr == NULL) return false;
    if (sol(curr->left, num, ans)) {
        return true;
    }
    num--;
    if (num == 0) {
        ans = curr->val;
        return true;
    }
    return sol(curr->right, num, ans);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int ans;
    sol(A, B, ans);
    return ans;
}