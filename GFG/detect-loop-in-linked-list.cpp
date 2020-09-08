bool detectLoop(Node* head) {
    if (!head) return false;
    for (Node *a = head, *b = head; a && b;) {
        a = a->next;
        b = b->next;
        if (b) {
            b = b->next;
            if (a == b) return true;
        }
    }
    return false;
}