#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, pre, ans;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        if (v[0] > v[v.size() - 1]) {
            reverse(v.begin(), v.end());
        }
        vector<int> post(n);
        post[n - 1] = 0;
        for (int i = v.size() - 2; i >= 0; i--) {
            post[i] = max(v[i + 1], post[i + 1]);
        }
        pre = v[0];
        ans = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < pre) {
                if (v[i] < post[i])
                    ans += (min(pre, post[i]) - v[i]);
            } else {
                pre = v[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}