/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
};

ListNode* mergeSort(ListNode* s, ListNode* e) {
    int random;
    e->next = NULL;
    if (s == e) {
        return s;
    }
    ListNode *l, *r;
    for (l = s, r = s; r != NULL;) {
        if (r->next == NULL) {
            break;
        }
        r = r->next->next;
        if (r == NULL) break;
        l = l->next;
    }
    r = mergeSort(l->next, e);
    l = mergeSort(s, l);
    s = NULL, e = NULL;
    for (; r != NULL && l != NULL;) {
        if (r->val < l->val) {
            if (s == NULL) {
                s = r;
                e = r;
            } else {
                e->next = r;
                e = r;
            }
            r = r->next;
        } else {
            if (s == NULL) {
                s = l;
                e = l;
            } else {
                e->next = l;
                e = l;
            }
            l = l->next;
        }
    }
    if (r == NULL) {
        e->next = l;
    } else {
        e->next = r;
    }
    return s;
}

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        ListNode* tail = head;

        for (; tail->next != NULL; tail = tail->next)
            ;

        return mergeSort(head, tail);
    }
};

int main() {
    Solution obj;
    ListNode *list = NULL, *curr;
    int n;
    while (1) {
        cin >> n;
        if (list == NULL) {
            list = new ListNode;
            curr = list;
        } else {
            curr->next = new ListNode;
            curr = curr->next;
        }
        curr->val = n;
        cin >> n;
        if (n == 0) break;
    }

    list = obj.sortList(list);
}