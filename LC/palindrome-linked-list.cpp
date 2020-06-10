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
    bool isPalindrome(ListNode* head) {
        string a, b;
        for (; head != NULL; head = head->next) {
            a += head->val;
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            b += a[i];
        }
        return a == b;
    }
};

// According to me, question is incorrect, reversing list must count as space, input must be read only