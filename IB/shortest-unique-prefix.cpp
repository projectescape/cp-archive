class Node {
   public:
    Node(char c = '\0') {
        val = c;
        children = vector<Node *>(26, NULL);
    }
    int childCount = 0, wordCount = 0;
    char val;
    vector<Node *> children;
};

vector<string> Solution::prefix(vector<string> &A) {
    Node *head = new Node, *temp;
    for (auto s : A) {
        temp = head;
        for (auto c : s) {
            if (!temp->children[c - 'a']) {
                temp->children[c - 'a'] = new Node(c);
                temp->childCount++;
            }
            temp->wordCount++;
            temp = temp->children[c - 'a'];
        }
    }
    vector<string> ans;
    string curr;
    for (auto s : A) {
        curr = "";
        temp = head->children[s[0] - 'a'];
        for (int i = 1;; i++) {
            curr += temp->val;
            if (temp->childCount <= 1 && temp->wordCount <= 1) {
                break;
            }
            temp = temp->children[s[i] - 'a'];
        }
        ans.push_back(curr);
    }
    return ans;
}
