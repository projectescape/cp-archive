void helper(Node* root, Node*& prev) {
    if (!root) return;
    helper(root->left, prev);
    root->left = prev;
    if (prev) prev->right = root;
    prev = root;
    helper(root->right, prev);
}

Node* bToDLL(Node* root) {
    Node* prev = NULL;
    helper(root, prev);
    if (root)
        while (root->left) root = root->left;
    return root;
}