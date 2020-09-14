#include <bits/stdc++.h>
using namespace std;

int helper(string &s, vector<int> &dp, int pos) {
    if (pos == s.size()) return 1;
    if (dp[pos] != -1) return dp[pos];
    dp[pos] = 0;
    string curr = "";
    for (int i = pos; i < s.size(); i++) {
        curr += s[i];
        if (stoi(curr) == 0) {
            break;
        }
        if (stoi(curr) <= 26) {
            dp[pos] += helper(s, dp, i + 1);
        } else {
            break;
        }
    }
    return dp[pos];
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        cin >> s;
        vector<int> dp(n, -1);

        cout << helper(s, dp, 0) << endl;
    }
    return 0;
}