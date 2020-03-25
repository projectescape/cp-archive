#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    ListNode(int n) {
        val = n;
        next = NULL;
    }
    int val;
    ListNode* next;
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL, *curr = NULL;
        int carry = 0, n;
        for (; l1 != NULL || l2 != NULL;) {
            n = carry;
            if (l1 != NULL) {
                n += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                n += l2->val;
                l2 = l2->next;
            }

            carry = n / 10;
            n = n % 10;
            if (!l3) {
                l3 = new ListNode(n);
                curr = l3;
            } else {
                curr->next = new ListNode(n);
                curr = curr->next;
            }
        }
        if (carry) {
            curr->next = new ListNode(carry);
        }
        return l3;
    }

    int main() {
        Solution s;
        ListNode *l1, *l2;

        l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);

        l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        ListNode* l3 = s.addTwoNumbers(l1, l2);
    }