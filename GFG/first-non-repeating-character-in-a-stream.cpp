#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        unordered_map<char, int> m;
        char c;
        list<char> l;
        for (int i = 0; i < n; i++) {
            cin >> c;
            m[c]++;
            if (m[c] == 1) {
                l.push_back(c);
            }
            if (l.empty()) {
                cout << -1 << " ";
                continue;
            } else {
                while (!l.empty() && m[l.front()] != 1) l.pop_front();
                if (l.empty()) {
                    cout << -1 << " ";
                } else {
                    cout << l.front() << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}