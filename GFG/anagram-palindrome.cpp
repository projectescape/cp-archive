#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        unordered_map<char, int> m;
        for (auto &i : s) {
            m[i]++;
        }
        bool used1 = false;
        bool printed = false;
        for (auto &i : m) {
            if (i.second % 2 == 1) {
                if (used1) {
                    cout << "No" << endl;
                    printed = true;
                    break;
                } else {
                    used1 = true;
                }
            }
        }
        if (!printed)
            cout << "Yes" << endl;
    }
    return 0;
}