/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findDiameter(TreeNode* curr, int& ans) {
    if (curr == NULL) return 0;
    int l = findDiameter(curr->left, ans);
    int r = findDiameter(curr->right, ans);
    ans = max(ans, l + r);
    return max(l, r) + 1;
}

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (root == NULL) return 0;
        findDiameter(root, ans);
        return ans;
    }
};