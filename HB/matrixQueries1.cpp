// https://hack.codingblocks.com/app/contests/128/p/813

#include <bits/stdc++.h>
using namespace std;

class matrix {
   public:
    int a = 1, b = 0, c = 0, d = 1;
};

int R;

void multMatrix(matrix& a, matrix b, matrix c) {
    a.a = (b.a * c.a + b.b * c.c) % R;
    a.b = (b.a * c.b + b.b * c.d) % R;
    a.c = (b.c * c.a + b.d * c.c) % R;
    a.d = (b.c * c.b + b.d * c.d) % R;
    return;
}

void buildTree(matrix* a, int s, int e, matrix* tree, int index = 1) {
    if (s == e) {
        tree[index].a = a[s].a;
        tree[index].b = a[s].b;
        tree[index].c = a[s].c;
        tree[index].d = a[s].d;
        return;
    }
    int mid = (s + e) / 2;

    int l = index * 2, r = index * 2 + 1;

    buildTree(a, s, mid, tree, l);
    buildTree(a, mid + 1, e, tree, r);

    multMatrix(tree[index], tree[l], tree[r]);

    return;
}

matrix query(matrix* tree, int ql, int qr, int sl, int sr, int index = 1) {
    if (qr < sl || ql > sr) {
        matrix a;
        return a;
    }

    if (ql <= sl && qr >= sr) {
        return tree[index];
    }

    int mid = (sl + sr) / 2;

    matrix ans;
    multMatrix(ans, query(tree, ql, qr, sl, mid, index * 2), query(tree, ql, qr, mid + 1, sr, index * 2 + 1));
    return ans;
}

int main() {
    int n, q;
    cin >> R >> n >> q;

    matrix a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    }

    matrix tree[4 * n + 1];

    buildTree(a, 0, n - 1, tree);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        matrix ans = query(tree, l, r, 0, n - 1);
        cout
            << ans.a << " " << ans.b << endl
            << ans.c << " " << ans.d << endl
            << endl;
    }
}