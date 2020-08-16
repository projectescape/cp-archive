bool comp(ListNode* a, ListNode* b) {
    return a->val < b->val;
}

ListNode* Solution::sortList(ListNode* A) {
    vector<ListNode*> v;
    if (!A) return A;
    for (; A; A = A->next) {
        v.push_back(A);
    }
    sort(v.begin(), v.end(), comp);
    v.push_back(NULL);
    for (int i = 0; i < v.size() - 1; i++) {
        v[i]->next = v[i + 1];
    }
    return v[0];
}