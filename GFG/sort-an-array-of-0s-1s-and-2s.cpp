#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        for (int i = 0, j = 0, k = n - 1; j <= k;) {
            if (v[j] == 0) {
                swap(v[i], v[j]);
                i++;
                if (j < i) {
                    j = i;
                }
            } else if (v[j] == 2) {
                swap(v[j], v[k]);
                k--;
            } else {
                j++;
            }
        }
        for (auto &i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}