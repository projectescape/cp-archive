#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, t
        // , sec
        ;
    // float angle;
    cin >> t;
    while (t--) {
        cin >> n;
        // angle = 360 / n;
        // sec = n / 4;
        // if (angle * sec == 90) {
        //     cout << "YES\n";
        // } else {
        //     cout << "NO\n";
        // }
        if (n % 4 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}