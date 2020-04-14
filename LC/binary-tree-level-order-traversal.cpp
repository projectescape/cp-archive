/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            q.push(NULL);
            vector<int> v;
            while (q.front() != NULL) {
                v.push_back(q.front()->val);
                if (q.front()->left != NULL) q.push(q.front()->left);
                if (q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            q.pop();
            ans.push_back(v);
        }
        return ans;
    }
};