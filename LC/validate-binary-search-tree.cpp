/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode* curr, vector<int>& v) {
    if (!curr) return;
    inorder(curr->left, v);
    v.push_back(curr->val);
    inorder(curr->right, v);
}

class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        vector<int> v;
        inorder(root, v);
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] <= v[i]) return false;
        }

        return true;
    }
};