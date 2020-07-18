TreeNode *construct(vector<int> &pre, int &ps, vector<int> &in, int is, int ie) {
    if (is > ie) return NULL;
    int index = is;
    for (; pre[ps] != in[index]; index++)
        ;
    TreeNode *ans = new TreeNode(pre[ps]);
    ps++;
    ans->left = construct(pre, ps, in, is, index - 1);
    ans->right = construct(pre, ps, in, index + 1, ie);
    return ans;
}

TreeNode *Solution::buildTree(vector<int> &pre, vector<int> &in) {
    if (pre.size() == 0) return NULL;
    int ps = 0;
    return construct(pre, ps, in, 0, in.size() - 1);
}