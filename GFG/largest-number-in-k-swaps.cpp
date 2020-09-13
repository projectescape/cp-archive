#include <bits/stdc++.h>
using namespace std;

void helper(string &s, int n, int pos, string &ans) {
    if (!n || pos == s.size()) {
        if (s > ans) ans = s;
        return;
    }
    helper(s, n, pos + 1, ans);
    for (int i = pos + 1; i < s.size(); i++) {
        if (s[i] > s[pos]) {
            swap(s[i], s[pos]);
            helper(s, n - 1, pos + 1, ans);
            swap(s[i], s[pos]);
        }
    }
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        cin >> s;
        string ans = s;
        helper(s, n, 0, ans);
        cout << ans << endl;
    }
    return 0;
}