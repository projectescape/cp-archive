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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        if (!root)
        {
            return "N,";
        }

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode *deserialize(string data, int &index)
    {
        if (index >= data.size())
        {
            return NULL;
        }
        string current = "";
        while (data[index] != ',')
        {
            current += data[index];
            index++;
        }
        index++;
        if (current == "N")
        {
            return NULL;
        }
        TreeNode *currNode = new TreeNode(stoi(current));
        currNode->left = deserialize(data, index);
        currNode->right = deserialize(data, index);
        return currNode;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int index = 0;
        return deserialize(data, index);
    }
};
