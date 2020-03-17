// https://www.spoj.com/problems/GSS1/
#include <bits/stdc++.h>
using namespace std;

// int query(int *tree, int ql, int qr, int sl, int sr, int index = 1) {
//         // Complete Overlap
//     if (ql <= sl && qr >= sr) {
//         return tree[index];
//     }

//     // Out of bound
//     if(qr<sl || ql>sr){
//         return 0;
//     }

// }

int buildTree(int *tree, int s, int e, int *a, int index = 1) {
    if (s == e) {
        tree[index] = a[s];
        return tree[index];
    }
    int mid = (s + e) / 2;

    tree[index] = max(buildTree(tree, s, mid, a, index * 2), buildTree(tree, mid + 1, e, a, index * 2 + 1));

    for (int i = s; i <= mid; i++) {
        for (int j = mid + 1; j <= e; j++) {
            tree[index] = max(tree[index], query(tree, i, j, s, e, index));
        }
    }

    // Pending partial overlap case

    return tree[index];
}

int main() {
    int n, m;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Build segment Tree here
    int tree[4 * n + 1];

    buildTree(tree, 0, n - 1, a);

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
    }
}