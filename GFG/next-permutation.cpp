#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, a, b, c, d;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        for (a = n - 2; a >= 0; a--) {
            if (v[a] < v[a + 1]) break;
        }
        if (a == -1) {
            sort(v.begin(), v.end());
            for (auto &i : v) cout << i << " ";
            cout << endl;
        } else {
            c = INT_MAX;
            for (b = a + 1; b < n; b++) {
                if (v[b] > v[a] && v[b] < c) {
                    d = b;
                    c = v[b];
                }
            }
            swap(v[a], v[d]);
            sort(v.begin() + a + 1, v.end());
            for (auto &i : v) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}