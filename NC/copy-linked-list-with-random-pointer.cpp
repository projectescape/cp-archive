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

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == NULL)
            return NULL;

        Node *newHead = new Node(head->val);

        Node *oldLL = head;
        Node *newLL = newHead;

        map<Node *, Node *> nodeMapping;

        while (oldLL != NULL)
        {
            if (oldLL->next != NULL)
            {
                Node *newNode = new Node(oldLL->next->val);
                newLL->next = newNode;
            }
            nodeMapping[oldLL] = newLL;
            oldLL = oldLL->next;
            newLL = newLL->next;
        }

        oldLL = head;
        newLL = newHead;

        while (oldLL != NULL)
        {
            if (oldLL->random != NULL)
            {
                newLL->random = nodeMapping[oldLL->random];
            }
            oldLL = oldLL->next;
            newLL = newLL->next;
        }

        return newHead;
    }
};
