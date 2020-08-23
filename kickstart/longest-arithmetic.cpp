#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n, ans, diff, curr;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n < 3) {
            cout << "Case #" << i << ": " << n << endl;
            continue;
        }

        curr = ans = 2;
        diff = a[1] - a[0];
        for (int i = 2; i < n; i++) {
            if (a[i] - a[i - 1] == diff) {
                curr++;
                continue;
            }
            diff = a[i] - a[i - 1];
            ans = max(ans, curr);
            curr = 2;
        }
        ans = max(curr, ans);
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}