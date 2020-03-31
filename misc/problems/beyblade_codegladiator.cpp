#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *a[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, ans = 0;
        cin >> n;
        int j = n - 1;
        vector<long long> g;
        vector<long long> opp;
        long long temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            g.push_back(temp);
        }
        sort(g.begin(), g.end());
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp >= g[j]) continue;

            if (temp == g[j] - 1) {
                ans++;
                j--;
                continue;
            }

            opp.push_back(temp);
        }
        sort(opp.begin(), opp.end());
        for (int i = opp.size() - 1; i >= 0; i--) {
            if (g[j] > opp[i]) {
                ans++;
                j--;
            }
        }
        cout << ans << endl;
    }
}
