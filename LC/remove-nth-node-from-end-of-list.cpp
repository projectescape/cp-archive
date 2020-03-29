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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) return NULL;
        ListNode *end = head, *curr = head;
        for (int i = 0; i < n; i++) {
            end = end->next;
        }
        while (end != NULL && end->next != NULL) {
            curr = curr->next;
            end = end->next;
        }
        if (end == NULL)
            head = head->next;
        else
            curr->next = curr->next->next;
        return head;
    }
};