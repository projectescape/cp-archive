/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void inorder(TreeNode* curr, int& k, int& ans) {
    if (!curr || k == 0) return;
    inorder(curr->left, k, ans);
    if (k == 1) {
        ans = curr->val;
    }
    inorder(curr->right, --k, ans);
}

class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, k, ans);
        return ans;
    }
};