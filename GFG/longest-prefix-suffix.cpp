#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[s.size() - 1]) {
                bool flag = true;
                for (int j = i - 1, k = s.size() - 2; j >= 0; j--, k--) {
                    if (s[j] != s[k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = i + 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}