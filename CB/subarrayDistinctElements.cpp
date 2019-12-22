// https :  //hack.codingblocks.com/app/contests/547/p/955

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp, ans = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> m;
        for (int j = i; j < n; j++) {
            auto it = m.find(v[j]);
            if (it == m.end()) {
                m.insert({v[j], 1});
                ans += (j - i + 1);
            } else {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}