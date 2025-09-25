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
    vector<int> dfsOutput;

    void dfs(TreeNode *node)
    {
        if (!node)
        {
            return;
        }

        dfs(node->left);
        dfsOutput.push_back(node->val);
        dfs(node->right);
    }

    bool isValidBST(TreeNode *root)
    {
        dfs(root);

        for (int i = 1; i < dfsOutput.size(); i++)
        {
            if (!(dfsOutput[i - 1] < dfsOutput[i]))
            {
                return false;
            }
        }
        return true;
    }
};
