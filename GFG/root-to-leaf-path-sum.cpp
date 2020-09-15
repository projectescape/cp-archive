bool hasPathSum(Node *node, int sum) {
    if (!node) {
        if (sum == 0) return true;
        return false;
    }
    return hasPathSum(node->left, sum - node->data) || hasPathSum(node->right, sum - node->data);
}