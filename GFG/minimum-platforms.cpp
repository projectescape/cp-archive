#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, curr, ans;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> in(n), out(n);
        for (auto &i : in) cin >> i;
        for (auto &i : out) cin >> i;
        sort(in.begin(), in.end());
        sort(out.begin(), out.end());
        curr = ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            for (; out[j] < in[i]; j++) {
                curr--;
            }
            curr++;
            ans = max(ans, curr);
        }
        cout << ans << endl;
    }
    return 0;
}