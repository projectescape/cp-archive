/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode* curr, vector<int>& ans) {
    if (curr == NULL) return;
    inorder(curr->left, ans);
    ans.push_back(curr->val);
    inorder(curr->right, ans);
}

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stack;
        while (1) {
            while (root) {
                stack.push(root);
                root = root->left;
            }
            if (stack.empty()) break;
            root = stack.top();
            stack.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};