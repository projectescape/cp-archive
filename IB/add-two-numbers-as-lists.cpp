ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry = false;
    ListNode *temp = A, *pre;
    while (1) {
        if (A && B) {
            A->val += B->val;
            if (carry) (A->val)++;
            if (A->val > 9) {
                carry = true;
                A->val %= 10;
            } else {
                carry = false;
            }
            pre = A;
            A = A->next;
            B = B->next;
        } else if (A) {
            if (!carry) break;
            while (A) {
                A->val++;
                if (A->val > 9) {
                    A->val %= 10;
                    pre = A;
                    A = A->next;
                } else {
                    carry = false;
                    break;
                }
            }
            if (carry) {
                pre->next = new ListNode(1);
            }
            break;
        } else if (B) {
            pre->next = B;
            if (!carry) break;
            while (B) {
                B->val++;
                if (B->val > 9) {
                    B->val %= 10;
                    pre = B;
                    B = B->next;
                } else {
                    carry = false;
                    break;
                }
            }
            if (carry) {
                pre->next = new ListNode(1);
            }
            break;
        } else
            break;
    }
    return temp;
}
