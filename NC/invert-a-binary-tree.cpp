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
    TreeNode *invertTreeRecusrive(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }

        TreeNode *right = root->right, *left = root->left;

        root->right = invertTree(left);
        root->left = invertTree(right);
        return root;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }

        queue<TreeNode *> q;
        q.push(root);

        TreeNode *right, *left, *curr;

        while (q.size() > 0)
        {

            curr = q.front();
            q.pop();
            if (curr)
            {
                right = curr->right;
                left = curr->left;

                curr->right = left;
                curr->left = right;

                q.push(right);
                q.push(left);
            }
        }

        return root;
    }
};
