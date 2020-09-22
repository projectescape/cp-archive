void helper(Node *&root, int &ans, int &h) {
    if (!root) return;
    ans = max(ans, h);
    h++;
    helper(root->left, ans, h);
    helper(root->right, ans, h);
    h--;
}

int height(Node *root) {
    int ans = 0;
    int h = 1;
    helper(root, ans, h);
    return ans;
}
