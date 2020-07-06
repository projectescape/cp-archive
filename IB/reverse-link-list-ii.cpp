ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (!A || !A->next) return A;
    stack<ListNode*> s;
    ListNode *temp = A, *pre = NULL;
    for (int i = 1;; i++, temp = temp->next) {
        if (i >= B && i <= C) {
            s.push(temp);
            if (i == C) {
                temp = temp->next;
                if (!pre) {
                    pre = s.top();
                    A = pre;
                    s.pop();
                }
                while (!s.empty()) {
                    pre->next = s.top();
                    s.pop();
                    pre = pre->next;
                }
                pre->next = temp;
                return A;
            }
        } else
            pre = temp;
    }
    return A;
}