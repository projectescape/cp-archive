/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* curr, ListNode*& ans) {
    if (curr->next == NULL) {
        ans = curr;
        curr->next = NULL;
        return curr;
    }
    reverse(curr->next, ans)->next = curr;
    curr->next = NULL;
    return curr;
}

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* ans = NULL;
        reverse(head, ans);
        return ans;
    }
};