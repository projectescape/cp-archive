ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (!A) return A;
    ListNode* temp;
    for (ListNode* curr = A; curr && curr->next;) {
        if (curr->next->val == curr->val) {
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return A;
}