#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;

bool comp(int &a, int &b) {
    if (m[a] != INT_MAX) {
        if (m[b] != INT_MAX) {
            return m[a] < m[b];
        } else {
            return true;
        }
    } else if (m[b] != INT_MAX) {
        return false;
    }
    return a < b;
}

int main() {
    int T, a, b;
    cin >> T;
    while (T--) {
        m.clear();
        cin >> a >> b;
        vector<int> v1(a), v2(b);
        for (int i = 0; i < a; i++) {
            cin >> v1[i];
            m[v1[i]] = INT_MAX;
        }
        for (int i = 0; i < b; i++) {
            cin >> v2[i];
            m[v2[i]] = i;
        }
        sort(v1.begin(), v1.end(), comp);
        for (auto &i : v1) cout << i << " ";
        cout << endl;
    }
    return 0;
}