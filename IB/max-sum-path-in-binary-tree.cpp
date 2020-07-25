/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int calcPath(TreeNode* A, unordered_map<TreeNode*, int>& m) {
    if (!A) return 0;
    if (m.find(A) == m.end()) {
        m[A] = max(max(calcPath(A->left, m), calcPath(A->right, m)), 0) + A->val;
    }
    return m[A];
}

void helper(TreeNode* A, unordered_map<TreeNode*, int>& m, int& ans) {
    if (!A) return;
    ans = max(ans, A->val);
    if (A->left) {
        ans = max(ans, A->val + m[A->left]);
    }
    if (A->right) {
        ans = max(ans, A->val + m[A->right]);
    }
    if (A->left && A->right) {
        ans = max(ans, A->val + m[A->left] + m[A->right]);
    }
    helper(A->left, m, ans);
    helper(A->right, m, ans);
}

int Solution::maxPathSum(TreeNode* A) {
    int ans = INT_MIN;
    unordered_map<TreeNode*, int> m;
    calcPath(A, m);
    helper(A, m, ans);
    return ans;
}
