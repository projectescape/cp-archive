#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        stack<ListNode*> s;

        for (; !(l1 == NULL && l2 == NULL);) {
            if (l1 == NULL) {
                s.push(l2);
                l2 = l2->next;
                while (l2 != NULL) {
                    s.push(l2);
                    l2 = l2->next;
                    ;
                }
                break;
            }
            if (l2 == NULL) {
                s.push(l1);
                l1 = l1->next;
                while (l1 != NULL) {
                    s.push(l1);
                    l1 = l1->next;
                }
                break;
            }
            if (l1->val < l2->val) {
                s.push(l1);
                l1 = l1->next;
            } else {
                s.push(l2);
                l2 = l2->next;
            }
        }
        while (!s.empty()) {
            s.top()->next = head;
            head = s.top();
            s.pop();
        }
        return head;
    }
};