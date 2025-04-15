/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode *A, int B)
{
    int cnt = 0;
    for (ListNode *node = A; node != NULL; node = node->next)
    {
        cnt++;
    }
    int half = cnt / 2 + 1;
    int pos = half - B;

    if (pos <= 0)
        return -1;

    int ans = A->val;
    ListNode *curr = A;
    for (int i = 0; i < pos; i++)
    {
        ans = curr->val;
        curr = curr->next;
    }
    return ans;
}
