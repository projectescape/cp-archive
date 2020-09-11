#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        string s;
        unordered_map<string, int> m;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            sort(s.begin(), s.end());
            m[s]++;
        }
        vector<int> v;
        for (auto &i : m) v.push_back(i.second);
        sort(v.begin(), v.end());
        for (auto &i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}