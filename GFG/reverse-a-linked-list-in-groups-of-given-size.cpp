struct node *reverse(struct node *head, int k) {
    if (!head) return NULL;
    node *pre = NULL, *next, *tail = head;
    for (int i = 0; i < k && head; i++) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    tail->next = reverse(head, k);
    return pre;
}
