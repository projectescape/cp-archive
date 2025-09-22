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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || head->next == NULL)
        {
            return head;
        }

        ListNode *next = head->next;
        head->next = NULL;
        ListNode *newHead = reverseList(next);
        next->next = head;
        return newHead;
    }

    void reorderList(ListNode *head)
    {

        ListNode *curr = head;
        int count = 0;

        while (curr)
        {
            count++;
            curr = curr->next;
        }

        count = (count + 1) / 2;

        curr = head;

        for (int i = 1; i < count; i++)
        {
            curr = curr->next;
        }

        ListNode *newList = curr->next;

        curr->next = NULL;

        newList = reverseList(newList);
        curr = head;

        while (curr && newList)
        {
            ListNode *currNext = curr->next, *newListNext = newList->next;
            curr->next = newList;
            newList->next = currNext;
            curr = currNext;
            newList = newListNext;
        }
    }
};
