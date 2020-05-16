/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* ans = head;
        ListNode *even = head->next, *evenHead = head->next;
        if (!even) return head;
        ListNode* odd = head;
        head = head->next->next;
        for (bool oe = true; head; head = head->next, oe = !oe) {
            if (oe) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
        }
        even->next = NULL;
        odd->next = evenHead;
        return ans;
    }
};