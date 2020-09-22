bool helper(Node*& r1, Node*& r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    if (r1->data != r2->data) return false;
    return helper(r1->left, r2->right) && helper(r1->right, r2->left);
}

bool isSymmetric(struct Node* root) {
    if (!root) return true;
    return helper(root->left, root->right);
}