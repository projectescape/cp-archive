#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        long long temp;
        cin >> n;
        vector<long long> v(n);
        for (auto &i : v) cin >> i;
        stack<long long> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 1) {
                if (s.top() < v[i]) {
                    s.pop();
                } else {
                    break;
                }
            }
            temp = v[i];
            v[i] = s.top();
            s.push(temp);
        }
        for (auto &i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}