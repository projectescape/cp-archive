TreeNode *construct(vector<int> &post, int &ps, vector<int> &in, int is, int ie) {
    if (is > ie) return NULL;
    int index = is;
    for (; post[ps] != in[index]; index++)
        ;
    TreeNode *ans = new TreeNode(post[ps]);
    ps--;
    ans->right = construct(post, ps, in, index + 1, ie);
    ans->left = construct(post, ps, in, is, index - 1);
    return ans;
}

TreeNode *Solution::buildTree(vector<int> &in, vector<int> &post) {
    if (post.size() == 0) return NULL;
    int ps = post.size() - 1;
    return construct(post, ps, in, 0, in.size() - 1);
}