/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* helper(ListNode* s, ListNode* e) {
    if (s == e) {
        s->next = NULL;
        return s;
    }
    ListNode* m = s;
    bool b = false;
    for (ListNode* temp = s; temp != e; temp = temp->next, b != b) {
        if (b) m = m->next;
    }
    ListNode* ans = m->next;
    s = helper(s, m);
    e = helper(ans, e);
    if (s->val < e->val) {
        ans = s;
        s = s->next;
    } else {
        ans = e;
        e = e->next;
    }
    m = ans;
    for (; s && e;) {
        if (s->val < e->val) {
            m->next = s;
            s = s->next;
        } else {
            m->next = e;
            e = e->next;
        }
        m = m->next;
    }
    if (s) {
        m->next = s;
    }
    if (e) {
        m->next = e;
    }
    return ans;
}

ListNode* Solution::sortList(ListNode* A) {
    ListNode* e = A;
    while (e->next) e = e->next;
    return helper(A, e);
}
