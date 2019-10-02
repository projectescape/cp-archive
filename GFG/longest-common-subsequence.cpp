// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int c, int d) {
    int dp[c + 1][d + 1];
    int ans = 0;
    for (int i = 0; i <= c; i++) dp[i][0] = 0;
    for (int i = 0; i <= d; i++) dp[0][i] = 0;
    for (int i = 1; i <= c; i++)
        for (int j = 1; j <= d; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            ans = max(ans, dp[i][j]);
        }
    return ans;
}

int main() {
    int T;  
    cin >> T;  // input no. of test cases
    while (T--) {
        int c, d;
        cin >> c >> d; //taking length of two strings
        string a, b;
        cin >> a >> b; //input 2 strings
        cout << lcs(a, b, c, d) << endl;  //Function Calling lcs
    }
    //code
    return 0;
}
