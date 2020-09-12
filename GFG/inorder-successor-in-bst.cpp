Node* inorder(Node* curr, Node* x, Node*& prev) {
    if (curr == NULL) return NULL;
    Node* n = inorder(curr->left, x, prev);
    if (n) return n;
    if (x == prev) return curr;
    prev = curr;
    return inorder(curr->right, x, prev);
}

Node* inOrderSuccessor(Node* root, Node* x) {
    Node* prev = NULL;
    return inorder(root, x, prev);
}