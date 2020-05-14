class Node {
   public:
    Node(char c) {
        val = c;
        v = vector<Node*>(26, NULL);
    }
    int freq = 0;
    int child = 0;
    vector<Node*> v;
    char val = '0';
};

void insertHelper(string& word, Node* curr, int pos = 0) {
    if ((curr->v[word[pos] - 'a']) == NULL) {
        curr->v[word[pos] - 'a'] = new Node(word[pos]);
    }
    if (pos < word.size() - 1) {
        (curr->v[word[pos] - 'a']->child)++;
        insertHelper(word, curr->v[word[pos] - 'a'], pos + 1);
    } else {
        (curr->v[word[pos] - 'a']->freq)++;
    }
}

bool searchHelper(string& word, Node* curr, int pos = 0) {
    if (curr->v[word[pos] - 'a'] == NULL) return false;
    if (pos < word.size() - 1) {
        return searchHelper(word, curr->v[word[pos] - 'a'], pos + 1);
    }
    return (curr->v[word[pos] - 'a']->freq) > 0 ? true : false;
}

bool startsHelper(string& word, Node* curr, int pos = 0) {
    if (curr->v[word[pos] - 'a'] == NULL) return false;
    if (pos < word.length() - 1) {
        return startsHelper(word, curr->v[word[pos] - 'a'], pos + 1);
    }
    return true;
}

class Trie {
    Node* parent;

   public:
    /** Initialize your data structure here. */
    Trie() {
        parent = new Node('0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertHelper(word, parent);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchHelper(word, parent);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsHelper(prefix, parent);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */