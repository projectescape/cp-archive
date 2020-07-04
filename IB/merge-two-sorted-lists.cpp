ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head;
    if (A && B) {
        if (A->val < B->val) {
            head = A;
            A = A->next;
        } else {
            head = B;
            B = B->next;
        }
    } else if (A) {
        return A;
    } else
        return B;
    for (ListNode* temp = head; A || B; temp = temp->next) {
        if (A && B) {
            if (A->val < B->val) {
                temp->next = A;
                A = A->next;
            } else {
                temp->next = B;
                B = B->next;
            }
        } else if (A) {
            temp->next = A;
            A = NULL;
        } else {
            temp->next = B;
            B = NULL;
        }
    }
    return head;
}

// ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
//     stack<ListNode*> s;
//     for (ListNode* temp = NULL; A != NULL || B != NULL; temp = temp->next) {
//         if (A != NULL && B != NULL) {
//             if (A->val < B->val) {
//                 s.push(A);
//                 A = A->next;
//             } else {
//                 s.push(B);
//                 B = B->next;
//             }
//         } else if (A != NULL) {
//             s.push(A);
//             A = A->next;
//         } else {
//             s.push(B);
//             B = B->next;
//         }
//     }
//     A = NULL;
//     while (!s.empty()) {
//         s.top()->next = A;
//         A = s.top();
//         s.pop();
//     }
//     return A;
// }