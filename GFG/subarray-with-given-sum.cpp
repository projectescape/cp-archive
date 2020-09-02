#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    int n, s, i, j, sum;
    bool flag;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        vector<int> v(n);
        for (i = 0; i < n; i++) cin >> v[i];
        flag = true;
        for (i = 0, j = 0, sum = 0; j < v.size(); j++) {
            sum += v[j];
            while (sum > s) {
                sum -= v[i];
                i++;
            }
            if (sum == s) {
                flag = false;
                cout << i + 1 << " " << j + 1 << endl;
                break;
            }
        }
        if (flag) cout << -1 << endl;
    }
    return 0;
}