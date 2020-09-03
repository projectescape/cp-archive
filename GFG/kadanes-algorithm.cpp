#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int ans = v[0];
        for (int i = 1; i < n; i++) {
            v[i] = max(v[i], v[i] + v[i - 1]);
            ans = max(ans, v[i]);
        }
        cout << ans << endl;
    }
    return 0;
}