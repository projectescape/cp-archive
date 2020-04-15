/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findMax(TreeNode* curr, int height, int& maxHeight) {
    if (curr->left == NULL) {
        if (curr->right == NULL) {
            maxHeight = max(height, maxHeight);
            return;
        }
        findMax(curr->right, height + 1, maxHeight);
        return;
    }
    findMax(curr->left, height + 1, maxHeight);
    if (curr->right != NULL) {
        findMax(curr->right, height + 1, maxHeight);
    }
}

class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int maxHeight = 0;
        findMax(root, 1, maxHeight);
        return maxHeight;
    }
};