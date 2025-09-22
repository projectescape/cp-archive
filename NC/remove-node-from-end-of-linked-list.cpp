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

//  5

// 5 6 7
//

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head, *curr = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        if (fast == NULL)
        {
            return head->next;
        }

        while (fast->next)
        {
            curr = curr->next;
            fast = fast->next;
        }
        if (n != 1)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr->next = NULL;
        }
        return head;
    }
};
