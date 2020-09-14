#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (v[i] <= 0) v[i] = n + 1;
        }
        int ans = n + 1;
        for (int i = 1; i <= n; i++) {
            if (abs(v[i]) <= n && v[abs(v[i])] > 0) {
                v[abs(v[i])] *= -1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (v[i] > 0) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}