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

TreeNode* constructTree(vector<int>& preorder, int i, int j) {
    if (i == j) return new TreeNode(preorder[i]);
    if (i > j) return NULL;
    int k = i;
    while (k < j) {
        k++;
        if (preorder[k] > preorder[i]) break;
    }
    if (preorder[k] > preorder[i])
        return new TreeNode(preorder[i], constructTree(preorder, i + 1, k - 1), constructTree(preorder, k, j));
    return new TreeNode(preorder[i], constructTree(preorder, i + 1, k), NULL);
}

class Solution {
   public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructTree(preorder, 0, preorder.size() - 1);
    }
};