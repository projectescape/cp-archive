#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cin >> n;
        int ans = -1;
        unordered_map<char, int> m;
        for (int i = 0, j = 0; j < s.size(); j++) {
            m[s[j]]++;
            while (m.size() > n) {
                m[s[i]]--;
                if (m[s[i]] == 0) {
                    m.erase(s[i]);
                }
                i++;
            }
            if (m.size() == n)
                ans = max(ans, j - i + 1);
        }
        cout << ans << endl;
    }
    return 0;
}