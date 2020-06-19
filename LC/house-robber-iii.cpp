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
unordered_map<TreeNode*, int> m;
class Solution {
   public:
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (m.find(root) != m.end()) return m[root];
        int ans1 = 0, ans2 = 0;
        ans1 += root->val;
        if (root->left != NULL) {
            ans2 += rob(root->left);
            ans1 += rob(root->left->left);
            ans1 += rob(root->left->right);
        }
        if (root->right != NULL) {
            ans2 += rob(root->right);
            ans1 += rob(root->right->left);
            ans1 += rob(root->right->right);
        }
        m[root] = max(ans1, ans2);
        return m[root];
    }
};