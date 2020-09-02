ListNode* Solution::deleteDuplicates(ListNode* A) {
    for (ListNode *curr = A, *prev = NULL, *temp = NULL; curr && curr->next;) {
        if (curr->val == curr->next->val) {
            for (temp = curr->next; temp && temp->val == curr->val; temp = temp->next)
                ;
            if (!prev) {
                A = temp;
                curr = temp;
            } else {
                prev->next = temp;
                curr = temp;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return A;
}
