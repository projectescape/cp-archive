bool isPalindrome(Node* head) {
    stack<int> s;
    for (Node* temp = head; temp; temp = temp->next) {
        s.push(temp->data);
    }
    while (!s.empty()) {
        if (s.top() != head->data) return false;
        s.pop();
        head = head->next;
    }
    return true;
}