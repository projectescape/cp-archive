void inorder(TreeNode* curr, vector<int>& ans) {
    if (!curr) return;
    inorder(curr->left, ans);
    ans.push_back(curr->val);
    inorder(curr->right, ans);
}

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    inorder(A, ans);
    return ans;
}

// vector<int> Solution::inorderTraversal(TreeNode* A) {
//     vector<int> ans;
//     stack<TreeNode*> s;
//     stack<int> l;
//     queue<TreeNode*> q;
//     s.push(A);
//     TreeNode* temp;
//     while (!s.empty()) {
//         if (!s.top()) {
//             s.pop();
//             ans.push_back(l.top());
//             l.pop();
//             continue;
//         }
//         temp = s.top();
//         s.pop();
//         l.push(temp->val);
//         if (temp->right)
//             s.push(temp->right);
//         s.push(NULL);
//         if (temp->left)
//             s.push(temp->left);
//     }
//     return ans;
// }