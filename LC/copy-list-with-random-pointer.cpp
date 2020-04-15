/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node *ans = NULL, *prev = NULL;
        unordered_map<Node*, Node*> m;
        m[NULL] = NULL;
        for (Node *i = NULL, *j = head; j != NULL;) {
            i = new Node(j->val);
            m[j] = i;
            if (ans == NULL) {
                ans = i;
                prev = i;
            } else {
                prev->next = i;
                prev = i;
            }
            j = j->next;
        }
        for (Node *i = ans, *j = head; j != NULL;) {
            i->random = m[j->random];
            i = i->next;
            j = j->next;
        }
        return ans;
    }
};