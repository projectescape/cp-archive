// https://practice.geeksforgeeks.org/problems/max-length-chain/1

int dp[105];
int maxChainLen(struct val p[], int n) {
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (p[j].second < p[i].first) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (maxi < dp[i])
            maxi = dp[i];
    }
    return maxi;
}