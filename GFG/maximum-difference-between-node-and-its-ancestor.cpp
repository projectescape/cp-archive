int helper(Node*& curr, int& ans) {
    if (!curr) return -1;
    int l = helper(curr->left, ans), r = helper(curr->right, ans);
    int ret = curr->data;
    if (l != -1) {
        ans = max(ans, curr->data - l);
        ret = min(ret, l);
    }
    if (r != -1) {
        ans = max(ans, curr->data - r);
        ret = min(ret, r);
    }
    return ret;
}

int maxDiff(Node* root) {
    int ans = INT_MIN;
    helper(root, ans);
    return ans;
}
