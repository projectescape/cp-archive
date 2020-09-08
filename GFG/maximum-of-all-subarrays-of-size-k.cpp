#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        int k, temp;
        cin >> n >> k;
        deque<pair<int, int>> dq;
        for (int i = 0; i < k; i++) {
            cin >> temp;
            if (dq.empty() || dq.front().first <= temp) {
                dq.push_front({temp, i});
            } else {
                while (!dq.empty() && dq.back().first <= temp) dq.pop_back();
                dq.push_back({temp, i});
            }
        }
        cout << dq.front().first << " ";
        for (int i = k; i < n; i++) {
            cin >> temp;
            if (dq.front().first <= temp) {
                dq.push_front({temp, i});
            } else {
                while (!dq.empty() && (dq.back().first <= temp || dq.back().second <= i - k)) dq.pop_back();
                dq.push_back({temp, i});
            }
            while (dq.front().second <= i - k) dq.pop_front();
            cout << dq.front().first << " ";
        }
        cout << endl;
    }
    return 0;
}