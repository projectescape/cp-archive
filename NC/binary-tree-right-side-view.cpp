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

class Solution
{
public:
    void findNodes(TreeNode *node, map<int, int> &levelToVal, int currLevel)
    {

        if (node == NULL)
            return;

        levelToVal[currLevel] = node->val;
        findNodes(node->left, levelToVal, currLevel + 1);
        findNodes(node->right, levelToVal, currLevel + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {

        map<int, int> levelToVal;

        findNodes(root, levelToVal, 0);

        vector<int> ans;

        for (auto i : levelToVal)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};
