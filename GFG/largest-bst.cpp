int calcMin(Node *&curr) {
    if (curr->left) return calcMin(curr->left);
    return curr->data;
}

int calcSize(Node *curr) {
    if (!curr) return 0;
    return calcSize(curr->left) + 1 + calcSize(curr->right);
}

bool helper(Node *curr, int &ans, int &pre) {
    if (!curr) return true;
    int p1 = INT_MIN, p2 = INT_MIN;
    if (helper(curr->left, ans, p1)) {
        if (helper(curr->right, ans, p2)) {
            if (p1 < curr->data && (!curr->right || curr->data < calcMin(curr->right))) {
                if (curr->right) {
                    pre = p2;
                } else {
                    pre = curr->data;
                }
                ans = max(ans, calcSize(curr));
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        helper(curr->right, ans, p2);
        return false;
    }
    return false;
}

int largestBst(Node *root) {
    int ans = 0;
    int pre = INT_MIN, mn = INT_MAX;
    helper(root, ans, pre);
    return ans;
}