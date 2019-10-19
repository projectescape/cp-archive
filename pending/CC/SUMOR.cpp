#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

int gcd(int a, int b)

{
    if (b == 0)
        return a;
    int x = gcd(b, a % b);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        ll n;
        ll ans = 0;
        cin >> n;
        vector<pair<ll, ll>> p;
        ll temp;
        for (ll i = 0; i < n; i++) {
            cin >> temp;
            p.push_back({temp, i});
        }
        ll size = p.size();
        sort(p.begin(), p.end());
        ll dp[size + 5];
        for (ll i = 0; i < size; i++) dp[i] = 0;
        dp[size - 1] = p[size - 1].first;
        for (ll i = size - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] | p[i].first;
        }
        for (ll i = 0; i < size; i++) {
            ans += dp[i];
        }
        for (ll i = 0; i < size; i++) {
            cout << p[i].second + 1 << " ";
        }
        cout << "\n";
        cout << ans << "\n";
    }
}