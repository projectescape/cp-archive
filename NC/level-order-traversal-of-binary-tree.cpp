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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        queue<pair<TreeNode *, int>> nodeLevelList;

        nodeLevelList.push({root, 1});

        while (nodeLevelList.size() > 0)
        {
            TreeNode *currentNode = nodeLevelList.front().first;
            int currentLevel = nodeLevelList.front().second;
            nodeLevelList.pop();

            if (!currentNode)
            {
                continue;
            }

            if (ans.size() < currentLevel)
            {
                ans.push_back({});
            }

            ans[currentLevel - 1].push_back(currentNode->val);

            nodeLevelList.push({currentNode->left, currentLevel + 1});
            nodeLevelList.push({currentNode->right, currentLevel + 1});
        }

        return ans;
    }
};
