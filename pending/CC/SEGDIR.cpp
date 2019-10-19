#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;

    while (T--) {
        ll n;
        cin >> n;
        int flag = 1;
        vector<pair<ll, pair<ll, ll>>> p;

        ll v, l, r;
        for (ll i = 0; (i < n); i++) {
            cin >> l;
            cin >> r;
            cin >> v;
            p.push_back({v, {l, r}});
        }
        sort(p.begin(), p.end());

        ll size = p.size();

        for (ll i = 0; (i < size) && flag; i++) {
            int k = 1;
            for (ll j = i + 1; j < size && p[j].first == p[i].first; j++) {
                if ((p[i].second.first >= p[j].second.first && p[i].second.first <= p[j].second.second) || (p[i].second.second >= p[j].second.first && p[i].second.second <= p[j].second.second)) {
                    // cout << p[i].first << " " << p[i].second.first << " " << p[i].second.second << endl;
                    // cout << p[j].first << " " << p[j].second.first << " " << p[j].second.second << endl;

                    if ((p[i].second.first == p[j].second.first || p[i].second.first == p[j].second.second) || (p[i].second.second == p[j].second.first || p[i].second.second == p[j].second.second)) {
                        k++;
                        if (k > 2) {
                            cout << "NO\n";
                            flag = 0;
                            break;
                        }
                    } else {
                        cout << "NO\n";
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag) {
            cout << "YES\n";
        }

        // sort(p.begin(),p.end(),soort);
    }
}