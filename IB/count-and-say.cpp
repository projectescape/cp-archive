string Solution::countAndSay(int n) {
    if (n == 1) return "1";
    string s = "11";
    if (n == 2) return s;
    int i = 3, j, count;

    while (i <= n) {
        int x = s.size();
        char y = s[0];
        count = 1;
        string ans;
        for (j = 1; j < x; j++) {
            if (s[j] == y) {
                count++;
            } else {
                ans += 48 + count;
                ans += y;
                y = s[j];
                count = 1;
            }
        }
        ans += 48 + count;
        ans += y;
        s = ans;
        i++;
    }
    return s;
}

// #include <bits/stdc++.h>
// using namespace std;

// string getNext(string curr, unordered_map<string, string> &dp) {
//     if (dp.find(curr) != dp.end()) return dp[curr];
//     string ans = "";
//     int cnt;
//     char c;
//     for (int i = curr.size() - 1; i >= 0 && dp.find(curr) == dp.end(); i = curr.size() - 1) {
//         c = curr[i];
//         cnt = 0;
//         while (i >= 0 && curr[i] == c) {
//             curr.pop_back();
//             cnt++;
//             i--;
//         }
//         ans = c + to_string(cnt) + ans;
//     }
//     ans = getNext(curr, dp) + ans;
//     return ans;
// }

// string Solution::
//     // string
//     countAndSay(int A) {
//     string ans = "1";
//     unordered_map<string, string> dp;
//     dp[""] = "";
//     for (int i = 1; i < A; i++) {
//         ans = getNext(ans, dp);
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }

// int main() {
//     int n;
//     cin >> n;
//     string ans = countAndSay(n);
//     cout << "ans : " << ans << endl;
//     // for (int i = 1; i <= n; i++)
//     //     cout << countAndSay(i) << endl;
// }