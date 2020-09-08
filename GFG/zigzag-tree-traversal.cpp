void helper(list<Node *> &q, vector<int> &ans, bool &f) {
    if (q.empty()) return;
    if (f) {
        q.push_back(NULL);
        while (q.front() != NULL) {
            ans.push_back(q.front()->data);
            if (q.front()->left)
                q.push_back(q.front()->left);
            if (q.front()->right)
                q.push_back(q.front()->right);
            q.pop_front();
        }
        q.pop_front();
    } else {
        q.push_front(NULL);
        while (q.back() != NULL) {
            ans.push_back(q.back()->data);
            if (q.back()->right)
                q.push_front(q.back()->right);
            if (q.back()->left)
                q.push_front(q.back()->left);
            q.pop_back();
        }
        q.pop_back();
    }
    f = !f;
    helper(q, ans, f);
}

vector<int> zigZagTraversal(Node *root) {
    list<Node *> l;
    if (root) {
        l.push_back(root);
    } else {
        return {};
    }
    vector<int> ans;
    bool right = true;
    helper(l, ans, right);
    return ans;
}