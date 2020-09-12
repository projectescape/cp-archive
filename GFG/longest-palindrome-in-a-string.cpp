#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        string ans(1, s[0]);
        bool flag;
        for (int i = 0, j = 1; j < s.size(); i++) {
            for (; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    flag = true;
                    for (int a = i + 1, b = j - 1; a < b; a++, b--) {
                        if (s[a] != s[b]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ans = "";
                        for (int a = i; a <= j; a++) ans += s[a];
                    }
                }
            }
            j = i + ans.size() + 1;
        }
        cout << ans << endl;
    }
    return 0;
}