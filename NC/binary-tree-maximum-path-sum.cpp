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


// Can be highly optimized by avoiding multiple traversals
// There is no need to store lowestPathBelow in a map, can be done in a single traversal
class Solution
{
public:
    unordered_map<TreeNode *, int> lowestPathBelow;

    int findLowestPathBelow(TreeNode *node)
    {
        if (!node)
            return 0;

        int ans =
            max({node->val,
                 findLowestPathBelow(node->left) + node->val,
                 findLowestPathBelow(node->right) + node->val});

        lowestPathBelow[node] = ans;
        return ans;
    }

    int findMaxPathSum(TreeNode *node)
    {
        if (!node)
            return 0;

        int leftPathMax = lowestPathBelow[node->left];
        int rightPathMax = lowestPathBelow[node->right];

        int ans = max({node->val,
                       node->val + leftPathMax,
                       node->val + rightPathMax,
                       node->val + leftPathMax + rightPathMax});

        if (node->right)
        {
            ans = max(ans, findMaxPathSum(node->right));
        }

        if (node->left)
        {
            ans = max(ans, findMaxPathSum(node->left));
        }

        return ans;
    }

    int maxPathSum(TreeNode *root)
    {
        findLowestPathBelow(root);

        lowestPathBelow[NULL] = 0;

        return findMaxPathSum(root);
    }
};
