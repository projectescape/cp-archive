// Find the number of operations required to covert one string to another string.
// Allowed operations are delete,insert,replace.
// cat to hat requires 1
// cat to car requires 1, cars require 2

#include <bits/stdc++.h>
using namespace std;

int editDistance(char a[], char b[]) {
    int dp[101][101];
    int m = strlen(a);
    int n = strlen(b);
    int q1, q2, q3;

    // Base Case
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 0; i <= n; i++) dp[i][0] = i;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // Insertion case
            q1 = dp[i][j - 1];
            // replacement case
            q2 = dp[i - 1][j - 1];
            // Deletion case
            q3 = dp[i - 1][j];
            // To check whether the char is same for input and output for a location
            dp[i][j] = min(q1, min(q2, q3)) + (a[i - 1] != b[j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    char a[100], b[100];
    cin >> a >> b;
    int ans = editDistance(a, b);
    cout << ans << endl;
}