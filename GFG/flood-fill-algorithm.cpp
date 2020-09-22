#include <bits/stdc++.h>
using namespace std;

void fill(int x, int y, int &a, int &b, int &o, int &n, vector<vector<int>> &v) {
    if (x < 0 || x >= a || y < 0 || y >= b || v[x][y] != o) return;
    v[x][y] = n;
    fill(x - 1, y, a, b, o, n, v);
    fill(x + 1, y, a, b, o, n, v);
    fill(x, y - 1, a, b, o, n, v);
    fill(x, y + 1, a, b, o, n, v);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, x, y, o, n;
        cin >> a >> b;
        vector<vector<int>> v(a, vector<int>(b));
        for (auto &i : v)
            for (auto &j : i) cin >> j;
        cin >> x >> y >> n;
        o = v[x][y];
        fill(x, y, a, b, o, n, v);
        for (auto &i : v)
            for (auto &j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}