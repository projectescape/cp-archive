bool comp(ListNode*& a, ListNode*& b) { return a->val > b->val; }

ListNode* Solution::mergeKLists(vector<ListNode*>& A) {
    if (A.size() == 0) return NULL;
    if (A.size() == 1) return A[0];
    make_heap(A.begin(), A.end(), comp);
    ListNode *ans, *temp;
    ans = temp = A[0];
    pop_heap(A.begin(), A.end(), comp);
    if (temp->next == NULL) {
        A.pop_back();
    } else {
        A[A.size() - 1] = temp->next;
        push_heap(A.begin(), A.end(), comp);
    }
    while (A.size() > 0) {
        temp->next = A[0];
        temp = temp->next;
        pop_heap(A.begin(), A.end(), comp);
        if (temp->next == NULL) {
            A.pop_back();
        } else {
            A[A.size() - 1] = temp->next;
            push_heap(A.begin(), A.end(), comp);
        }
    }
    return ans;
}