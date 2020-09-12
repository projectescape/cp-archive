#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, ans, f;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cin >> f;
        ans = 0;
        for (int i = 0, j = 0; j < n; j++) {
            if (v[j] == 0) {
                f--;
                if (f < 0) {
                    while (v[i] == 1) i++;
                    i++;
                    f = 0;
                }
            }
            ans = max(ans, j - i + 1);
        }
        cout << ans << endl;
    }
    return 0;
}