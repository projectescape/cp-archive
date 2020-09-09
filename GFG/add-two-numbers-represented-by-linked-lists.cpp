struct Node* addTwoLists(struct Node* first, struct Node* second) {
    Node *curr, *pre, *next, *curr1, *pre1;
    for (curr = first, pre = NULL; curr;) {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        if (!next) {
            first = pre;
        }
    }
    for (curr = second, pre = NULL; curr;) {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        if (!next) {
            second = pre;
        }
    }
    int carry = 0;
    for (curr = first, curr1 = second; curr && curr1; curr = curr->next, curr1 = curr1->next) {
        pre = curr;
        pre1 = curr1;
        curr->data += (curr1->data + carry);
        carry = curr->data / 10;
        curr->data %= 10;
    }
    if (curr) {
        while (curr && carry) {
            pre = curr;
            curr->data += (carry);
            carry = curr->data / 10;
            curr->data %= 10;
            curr = curr->next;
        }
    } else if (curr1) {
        pre->next = curr1;
        curr = curr1;
        while (curr && carry) {
            pre = curr;
            curr->data += (carry);
            carry = curr->data / 10;
            curr->data %= 10;
            curr = curr->next;
        }
    }
    if (carry) {
        pre->next = new Node(1);
    }
    for (curr = first, pre = NULL; curr;) {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        if (!next) {
            first = pre;
        }
    }
    return first;
}