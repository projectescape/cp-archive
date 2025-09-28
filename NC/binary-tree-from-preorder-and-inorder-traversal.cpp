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
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode *buildTreeRec(vector<int> &preorder,
                           int inorderStart, int inorderEnd)
    {

        if (inorderStart > inorderEnd)
        {
            return NULL;
        }

        int currentNodeVal = preorder[preorderIndex];
        TreeNode *currentNode = new TreeNode(currentNodeVal);
        preorderIndex++;

        int currentNodeInorderIndex = inorderMap[currentNodeVal];

        currentNode->left = buildTreeRec(preorder, inorderStart, currentNodeInorderIndex - 1);

        currentNode->right = buildTreeRec(preorder, currentNodeInorderIndex + 1, inorderEnd);

        return currentNode;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        for (int i = 0; i < preorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return buildTreeRec(preorder, 0, preorder.size() - 1);
    }
};
