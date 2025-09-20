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
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;

        ListNode *slow = head, *fast = head;

        while (slow && head)
        {
            fast = fast->next;
            if (fast == NULL)
            {
                return false;
            }
            fast = fast->next;
            if (fast == NULL)
            {
                return false;
            }
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};
