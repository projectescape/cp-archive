
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n = 0;
    ListNode* head = A;

    while (head != NULL) {
        n++;
        head = (*head).next;
    }
    B = B % n;
    if (B == n || B == 0)
        return A;

    ListNode* l2 = A;
    ListNode* l1 = A;
    for (int i = 0; i < (n - B); i++) {
        l2 = (*l2).next;
    }

    for (int i = 0; i < (n - B - 1); i++) {
        l1 = (*l1).next;
    }
    (*l1).next = NULL;
    ListNode* h = l2;
    for (int i = 0; i < (B - 1); i++) {
        h = (*h).next;
    }
    (*h).next = A;
    return l2;
}
