// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Node *newHead = NULL;
Node *reverse(Node *n) {
    if (n->next == NULL) {
        newHead = n;
        return n;
    }
    reverse(n->next)->next = n;
    return n;
}
Node *reverseList(Node *head) {
    reverse(head);
    head->next = NULL;
    return newHead;
    // Your code here
}