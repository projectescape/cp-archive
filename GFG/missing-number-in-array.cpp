#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, temp;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<bool> v(n + 1, false);
        for (int i = 1; i < n; i++) {
            cin >> temp;
            v[temp] = true;
        }
        for (int i = 1; i < v.size(); i++) {
            if (!v[i]) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}