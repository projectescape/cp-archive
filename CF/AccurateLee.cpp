#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, pos, temp, fZero, lZero, fOne, bOne;
    string s, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<bool> inc(n, true);
        cin >> s;
        fZero = lZero = fOne = bOne = -1;

        for (temp = 0; temp < n; temp++) {
            if (s[temp] == '0') {
                fZero = temp;
                break;
            }
        }
        for (temp = fZero + 1; temp < n; temp++) {
            if (s[temp] == '0') {
                lZero = temp;
            }
        }
        if (fZero != -1)
            for (temp = 0; temp < fZero; temp++) {
                if (s[temp] == '1') {
                    fOne = temp;
                    break;
                }
            }
        if (lZero != -1)
            for (temp = fZero + 1; temp < lZero; temp++) {
                if (s[temp] == '1') {
                    bOne = temp;
                    break;
                }
            }
        if (fOne != -1)
            for (temp = fOne; temp < fZero; temp++) inc[temp] = false;
        if (fOne != -1 && lZero != -1) {
            for (temp = fZero + 1; temp <= lZero; temp++) {
                inc[temp] = false;
            }
        } else if (fOne == -1 && bOne != -1 && lZero != -1) {
            for (temp = bOne; temp < lZero; temp++) {
                inc[temp] = false;
            }
        }

        for (pos = 0; pos < n; pos++) {
            if (inc[pos]) cout << s[pos];
        }
        cout << endl;
    }
    return 0;
}