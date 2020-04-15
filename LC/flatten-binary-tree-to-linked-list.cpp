/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preorder(TreeNode* curr, queue<TreeNode*>& q) {
    if (curr == NULL) return;
    q.push(curr);
    preorder(curr->left, q);
    preorder(curr->right, q);
}

class Solution {
   public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        queue<TreeNode*> q;
        preorder(root, q);
        TreeNode* curr = root;
        q.pop();
        while (!q.empty()) {
            curr->right = q.front();
            curr->left = NULL;
            curr = q.front();
            q.pop();
        }
        return;
    }
};