int helper(Node *&curr) {
    if (!curr) return 0;
    int sum = curr->data;
    curr->data = helper(curr->left) + helper(curr->right);
    return sum + curr->data;
}

void toSumTree(Node *node) {
    helper(node);
}