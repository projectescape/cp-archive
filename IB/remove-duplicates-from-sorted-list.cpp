ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (!A) return A;
    for (; A->next && A->next->val == A->val; A = A->next)
        ;
    ListNode *temp = A->next, *curr = A;
    while (temp) {
        for (; temp && temp->next && temp->next->val == temp->val; temp = temp->next)
            ;
        curr->next = temp;
        curr = temp;
        temp = temp->next;
    }
    curr->next = NULL;
    return A;
}