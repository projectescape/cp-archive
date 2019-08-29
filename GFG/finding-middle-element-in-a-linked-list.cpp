// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

int getMiddle(Node *head) {
    Node *middle = head;
    while (1) {
        head = head->next;
        if (head != NULL) {
            head = head->next;
            middle = middle->next;
        }
        if (head == NULL) break;
    }
    return middle->data;
}