#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, ans;
    string s;
    cin >> t;

    while (t--) {
        cin >> s;
        vector<int> v(26, 0);
        for (auto i : s) {
            v[i - 'a']++;
        }
        ans = 0;
        for (auto i : v) {
            if (i > 1) {
                ans += (i - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}