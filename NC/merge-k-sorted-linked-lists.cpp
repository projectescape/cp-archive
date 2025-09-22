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
    struct comp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, comp> pq;

        for (auto i : lists)
        {
            pq.push(i);
        }

        ListNode *head = NULL, *curr = NULL, *prev;

        while (pq.size() > 0)
        {
            if (head == NULL)
            {
                head = pq.top();
                curr = pq.top();
            }
            else
            {
                prev = curr;
                curr = pq.top();
                prev->next = curr;
            }
            pq.pop();
            if (curr->next)
            {
                pq.push(curr->next);
            }
        }

        return head;
    }
};
