int helper(Node *&curr, int &ans) {
    if (!curr || !ans) return 0;
    if (curr->left) {
        if (curr->right) {
            if (helper(curr->left, ans) + helper(curr->right, ans) != curr->data) {
                ans = 0;
            }
        } else {
            if (helper(curr->left, ans) != curr->data) {
                ans = 0;
            }
        }
    } else if (curr->right) {
        if (helper(curr->right, ans) != curr->data) {
            ans = 0;
        }
    }
    return curr->data;
}

int isSumProperty(Node *root) {
    int ans = 1;
    helper(root, ans);
    return ans;
}