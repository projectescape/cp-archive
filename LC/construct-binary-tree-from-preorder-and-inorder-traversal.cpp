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

// I index in pre, j, k indexes in in
TreeNode* genTree(vector<int>& preorder, vector<int>& inorder, int& i, int j, int k) {
    if (j == k) return new TreeNode(inorder[j], NULL, NULL);
    if (j > k) {
        i--;
        return NULL;
    };
    int index = j;
    while (1) {
        if (preorder[i] == inorder[index]) {
            break;
        }
        index++;
    }
    return new TreeNode(preorder[i], genTree(preorder, inorder, ++i, j, index - 1), genTree(preorder, inorder, ++i, index + 1, k));
}

class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return genTree(preorder, inorder, i, 0, preorder.size() - 1);
    }
};