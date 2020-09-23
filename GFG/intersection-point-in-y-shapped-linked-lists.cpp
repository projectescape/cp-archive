int intersectPoint(Node* head1, Node* head2) {
    int a = 0, b = 0;
    for (Node* temp = head1; temp; temp = temp->next, a++)
        ;
    for (Node* temp = head2; temp; temp = temp->next, b++)
        ;
    if (a > b)
        for (int i = 0; i < a - b; i++, head1 = head1->next)
            ;
    else
        for (int i = 0; i < b - a; i++, head2 = head2->next)
            ;
    while (head1) {
        if (head1 == head2) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}
