#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        priority_queue<int, vector<int>, greater<int>> q;
        int temp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            q.push(temp);
        }
        long long ans = 0;
        while (q.size() >= 2) {
            temp = q.top();
            q.pop();
            temp += q.top();
            q.pop();
            ans += temp;
            q.push(temp);
        }
        cout << ans << endl;
    }
    return 0;
}