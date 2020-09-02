#include <bits/stdc++.h>
using namespace std;

bool helper(int s, int e, int &temp, vector<int> &v) {
    if (s > e) return false;
    int m = (s + e) / 2;
    if (v[m] == temp) return true;
    if (temp < v[m]) return helper(s, m - 1, temp, v);
    return helper(m + 1, e, temp, v);
}

int main() {
    int T, n, ans, temp;
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                temp = v[i] + v[j];
                if (helper(j + 1, v.size() - 1, temp, v)) {
                    ans++;
                }
                for (; j + 1 < v.size() && v[j + 1] == v[j]; j++)
                    ;
            }
            for (; i + 1 < v.size() && v[i + 1] == v[i]; i++)
                ;
        }
        if (ans) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}