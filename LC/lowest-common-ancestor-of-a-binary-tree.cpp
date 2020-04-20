/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool bfsSearch(TreeNode*& curr, TreeNode*& toFind) {
    if (curr == NULL) return false;
    if (curr->val == toFind->val) return true;
    //         Search in subtree
    queue<TreeNode*> q;
    q.push(curr->right);
    q.push(curr->left);
    TreeNode* temp = NULL;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == NULL) continue;
        if (temp->val == toFind->val) {
            //                 Handle Return
            return true;
        }
        q.push(temp->right);
        q.push(temp->left);
    }
    //         Handle Parent return
    return false;
}

pair<char, TreeNode*> dfsHelper(TreeNode* curr, TreeNode* p, TreeNode* q) {
    if (curr == NULL) {
        //         Handle Return
        return {'n', NULL};
    }
    if (curr->val == p->val) {
        if (bfsSearch(curr, q)) {
            return {'a', p};
        }
        return {'p', NULL};
    }
    if (curr->val == q->val) {
        if (bfsSearch(curr, p)) {
            return {'a', q};
        }
        return {'q', NULL};
    }
    pair<char, TreeNode*> ret;
    ret = dfsHelper(curr->left, p, q);
    if (ret.first == 'a') return ret;
    if (ret.first == 'p') {
        //         Search q in right
        if (bfsSearch(curr->right, q)) {
            return {'a', curr};
        }
        return {'p', NULL};
    }
    if (ret.first == 'q') {
        //         Search p in right
        if (bfsSearch(curr->right, p)) {
            return {'a', curr};
        }
        return {'q', NULL};
    }

    return dfsHelper(curr->right, p, q);
    return {'n', NULL};
}

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //         Apply DFS to find p or q
        return dfsHelper(root, p, q).second;
    }
};