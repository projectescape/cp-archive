#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    node *left = NULL, *right = NULL;
    int val;
    node(int v = 0, node* l = NULL, node* r = NULL) {
        val = v;
        left = l;
        right = r;
    }
};

node* helper(vector<int>& v, int s, int e) {
    if (s > e) return NULL;
    int m = (s + e) / 2;
    return new node(v[m], helper(v, s, m - 1), helper(v, m + 1, e));
}

void preorder(node* curr) {
    if (!curr) return;
    cout << curr->val << " ";
    preorder(curr->left);
    preorder(curr->right);
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n);
        for (auto& i : v) cin >> i;
        preorder(helper(v, 0, n - 1));
        cout << endl;
    }
    return 0;
}