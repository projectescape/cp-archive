#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, r, c;
    cin >> T;
    while (T--) {
        cin >> r >> c;
        vector<vector<int>> g(r, vector<int>(c)), f(r, vector<int>(c, INT_MAX));
        vector<vector<bool>> v(r, vector<bool>(c, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> g[i][j];
                if (g[i][j] == 1) {
                    g[i][j] = 2;
                } else if (g[i][j] == 2) {
                    g[i][j] = 1;
                }
                if (g[i][j] == 1) {
                    q.push({i, j});
                    f[i][j] = 0;
                }
            }
        }
        int a, b;
        while (!q.empty()) {
            a = q.front().first;
            b = q.front().second;
            q.pop();
            if (v[a][b]) {
                continue;
            } else {
                v[a][b] = true;
            }
            if (a - 1 >= 0) {
                if (g[a - 1][b] == 2 && !v[a - 1][b]) {
                    f[a - 1][b] = min(f[a - 1][b], f[a][b] + 1);
                    q.push({a - 1, b});
                }
            }
            if (a + 1 < r) {
                if (g[a + 1][b] == 2 && !v[a + 1][b]) {
                    f[a + 1][b] = min(f[a + 1][b], f[a][b] + 1);
                    q.push({a + 1, b});
                }
            }
            if (b + 1 < c) {
                if (g[a][b + 1] == 2 && !v[a][b + 1]) {
                    f[a][b + 1] = min(f[a][b + 1], f[a][b] + 1);
                    q.push({a, b + 1});
                }
            }
            if (b - 1 >= 0) {
                if (g[a][b - 1] == 2 && !v[a][b - 1]) {
                    f[a][b - 1] = min(f[a][b - 1], f[a][b] + 1);
                    q.push({a, b - 1});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 2) {
                    ans = max(ans, f[i][j]);
                }
            }
        }
        if (ans == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}