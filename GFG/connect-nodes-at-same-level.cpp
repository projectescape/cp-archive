void connect(Node* p) {
    if (!p) return;
    queue<Node*> q;
    q.push(p);
    q.push(NULL);
    Node* temp;
    while (q.size() > 1) {
        temp = q.front();
        q.pop();
        if (!temp) {
            q.push(NULL);
            continue;
        }
        temp->nextRight = q.front();
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}
