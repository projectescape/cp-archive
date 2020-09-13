class comp {
   public:
    bool operator()(Node* a, Node* b) {
        return (a->data) > (b->data);
    }
};

Node* mergeKLists(Node* arr[], int N) {
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (int i = 0; i < N; i++) {
        pq.push(arr[i]);
    }
    Node *ans = pq.top(), *temp = pq.top();
    pq.pop();
    if (ans->next) pq.push(ans->next);
    while (!pq.empty()) {
        temp->next = pq.top();
        temp = temp->next;
        pq.pop();
        if (temp->next) {
            pq.push(temp->next);
        }
    }
    return ans;
}