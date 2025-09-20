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
// 0 -> 1 -> 2 -> 3
// prev  curr  next

class Solution
{
public:
    ListNode *reverseListRecursion(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        ListNode *next = head->next;
        head->next = NULL;

        if (next != NULL)
        {
            ListNode *reversedList = reverseListRecursion(next);
            next->next = head;
            return reversedList;
        }
        return head;
    }

    ListNode *reverseList(ListNode *head)
    {

        return reverseListRecursion(head);
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *prev = NULL, *curr = head, *next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
