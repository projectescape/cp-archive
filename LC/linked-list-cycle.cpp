/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* tail = head->next->next;
        for (; tail != NULL; tail = tail->next->next) {
            if (tail->next == NULL) return false;
            head = head->next;
            if (head == tail) return true;
        }
        return false;
    }
};