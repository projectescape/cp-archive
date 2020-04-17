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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode *temp = NULL;
        for (temp = headA; temp != NULL; temp = temp->next) l1++;
        for (temp = headB; temp != NULL; temp = temp->next) l2++;
        if (l1 > l2) {
            for (int i = 0; i < (l1 - l2); i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < (l2 - l1); i++) {
                headB = headB->next;
            }
        }
        for (; headA != NULL; headA = headA->next, headB = headB->next)
            if (headA == headB) return headA;

        return NULL;
    }
};