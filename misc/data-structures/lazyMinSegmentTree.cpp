#include <bits/stdc++.h>
using namespace std;

int lazy[1000] = {0};

void buildTree(int *a, int s, int e, int *tree, int index) {
    if (s == e) {
        tree[index] = a[s];
        return;
    }

    // Recursive case
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid + 1, e, tree, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int query(int *tree, int ss, int se, int qs, int qe, int index) {
    if (ss >= qs && se <= qe) {
        // Complete overlap, return directly
        return tree[index];
    }

    if (qe < ss || qs > se) {
        // No overlap
        return INT_MAX;
    }

    // Partial Overlap
    int mid = (ss + se) / 2;
    return min(query(tree, ss, mid, qs, qe, 2 * index), query(tree, mid + 1, se, qs, qe, 2 * index + 1));
}

void updateNode(int *tree, int ss, int se, int i, int increment, int index) {
    if (i > se || i < ss) {
        // out of bound - no overlap
        return;
    }
    if (se == ss) {
        // Leaf Node
        tree[index] += increment;
        return;
    }
    // Partial overlap, call left, right
    int mid = (ss + se) / 2;

    updateNode(tree, ss, mid, i, increment, 2 * index);
    updateNode(tree, mid + 1, se, i, increment, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index) {
    if (r < ss || l > se) {
        // Out of bound
        return;
    }
    if (ss == se) {
        // Leaf node
        tree[index] += inc;
        return;
    }
    // left and right both
    int mid = (se + ss) / 2;
    updateRange(tree, ss, mid, l, r, inc, 2 * index);
    updateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {
    // First resolve lazy value at current node

    if (lazy[index] != 0) {
        tree[index] += lazy[index];

        // If not leaf
        if (ss != se) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }

        lazy[index] = 0;
    }

    // Out of bounds
    if (r < ss || l > se) {
        return;
    }

    if (ss >= l && se <= r) {
        tree[index] += inc;
        if (ss != se) {
            lazy[2 * index] += inc;
            lazy[2 * index + 1] += inc;
        }
        return;
    }

    int mid = (se + ss) / 2;
    updateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
    updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}
int queryLazy(int *tree, int ss, int se, int qs, int qe, int index) {
    if (lazy[index] != 0) {
        tree[index] += lazy[index];

        // If not leaf
        if (ss != se) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }

        lazy[index] = 0;
    }

    if (ss >= qs && se <= qe) {
        // Complete overlap, return directly
        return tree[index];
    }

    if (qe < ss || qs > se) {
        // No overlap
        return INT_MAX;
    }

    // Partial Overlap
    int mid = (ss + se) / 2;
    return min(queryLazy(tree, ss, mid, qs, qe, 2 * index), queryLazy(tree, mid + 1, se, qs, qe, 2 * index + 1));
}

int main() {
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);

    // Size will be maximum 4n+1
    int *tree = new int[4 * n + 1];

    buildTree(a, 0, n - 1, tree, 1);

    for (int i = 1; i <= 13; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;

    // int l, r;
    // cin >> l >> r;

    // cout << query(tree, 0, n - 1, l, r, 1) << endl;

    // updateNode(tree, 0, n - 1, 2, 10, 1);
    // updateNode(tree, 0, n - 1, 3, 15, 1);
    updateRangeLazy(tree, 0, n - 1, 2, 3, 10, 1);

    int q = 6;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << queryLazy(tree, 0, n - 1, l, r, 1) << endl;
    }

    return 0;
}