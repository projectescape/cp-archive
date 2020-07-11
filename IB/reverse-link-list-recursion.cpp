ListNode* rev(ListNode* a, ListNode** head) {
    if (a->next == NULL) {
        (*head) = a;
        return a;
    }
    rev(a->next, head)->next = a;
    return a;
}

ListNode* Solution::reverseList(ListNode* A) {
    ListNode* head;
    rev(A, &head)->next = NULL;
    return head;
}