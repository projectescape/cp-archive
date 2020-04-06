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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        stack<ListNode*> s;
        int comp, index;
        for (auto i : lists) {
            if (i == NULL) n--;
        }
        while (n > 0) {
            comp = INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == NULL) continue;
                if (lists[i]->val < comp) {
                    comp = lists[i]->val;
                    index = i;
                }
            }
            s.push(lists[index]);
            lists[index] = lists[index]->next;
            if (lists[index] == NULL) n--;
        }
        ListNode* head = NULL;
        while (!s.empty()) {
            s.top()->next = head;
            head = s.top();
            s.pop();
        }
        return head;
    }
};