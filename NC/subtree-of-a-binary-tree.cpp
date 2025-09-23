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
    vector<TreeNode *> findNode(TreeNode *root, int val)
    {
        vector<TreeNode *> ans;
        if (!root)
        {
            return ans;
        }

        if (root->val == val)
        {
            ans.push_back(root);
        }

        vector<TreeNode *> leftAns = findNode(root->left, val);
        vector<TreeNode *> rightAns = findNode(root->right, val);

        ans.insert(ans.end(), leftAns.begin(), leftAns.end());
        ans.insert(ans.end(), rightAns.begin(), rightAns.end());

        return ans;
    }

    bool isEqual(TreeNode *original, TreeNode *comp)
    {
        if (original && comp)
        {
            if (original->val == comp->val)
            {
                return isEqual(original->left, comp->left) && isEqual(original->right, comp->right);
            }
            else
            {
                return false;
            }
        }
        if (!original && !comp)
        {
            return true;
        }
        return false;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        vector<TreeNode *> nodes = findNode(root, subRoot->val);

        for (TreeNode *node : nodes)
        {
            if (isEqual(node, subRoot))
            {
                return true;
            }
        }

        return false;
    }
};
