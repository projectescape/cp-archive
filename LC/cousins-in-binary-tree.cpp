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
class Solution {
   public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y) return false;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp == NULL) {
                if (q.empty()) return false;
                q.push(NULL);
                continue;
            }
            if (temp->val == x) {
                while (q.front() != NULL) {
                    temp = q.front();
                    q.pop();
                    if (temp->val == y) return true;
                }
                return false;
            }
            if (temp->val == y) {
                while (q.front() != NULL) {
                    temp = q.front();
                    q.pop();
                    if (temp->val == x) return true;
                }
                return false;
            }
            if (temp->left != NULL && temp->right != NULL) {
                if (temp->left->val == x && temp->right->val == y) return false;
                if (temp->left->val == y && temp->right->val == x) return false;
            }
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
        return false;
    }
};