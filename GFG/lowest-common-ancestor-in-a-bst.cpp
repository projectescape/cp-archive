Node* LCA(Node* root, int n1, int n2) {
    if (!root) return NULL;
    Node *l = LCA(root->left, n1, n2), *r = LCA(root->right, n1, n2);
    if (l && r) return root;
    if (l) {
        if (root->data == n1 || root->data == n2)
            return root;
        else
            return l;
    }
    if (r) {
        if (root->data == n1 || root->data == n2)
            return root;
        else
            return r;
    }
    if (root->data == n1 || root->data == n2) return root;
    return NULL;
}
