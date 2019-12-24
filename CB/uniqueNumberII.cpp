// https://hack.codingblocks.com/app/practice/5/p/463

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i = 0, a, b = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        b = b ^ a;
    }
    for (i = 0;; i++) {
        if ((b & (1 << i))) {
            break;
        }
    }
    n = 0;
    for (int j = 0; j < v.size(); j++) {
        if (v[j] & (1 << i)) {
            n = n ^ v[j];
        }
    }
    b = b ^ n;
    if (b < n) {
        cout << b << " " << n;
        return 0;
    }
    cout << n << " " << b;
    return 0;
}
