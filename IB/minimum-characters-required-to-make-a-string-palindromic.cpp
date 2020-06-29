int Solution::solve(string A) {
    if (A.size() <= 1) return 0;
    int e = 0;
    int j, k;
    for (int i = 1; i < A.size(); i++) {
        for (j = i - 1, k = i; j >= 0 && k < A.size(); j--, k++) {
            if (A[j] == A[k]) {
                if (j == 0) e = k;
            } else
                break;
        }
        for (j = i - 2, k = i; j >= 0 && k < A.size(); j--, k++) {
            if (A[j] == A[k]) {
                if (j == 0) e = k;
            } else
                break;
        }
    }
    return A.size() - e - 1;
}

// bool checkP(int i, int j, vector<vector<int>> &dp, string &a) {
//     if (dp[i][j] != -1) {
//         if (dp[i][j] == 1)
//             return true;
//         else
//             return false;
//     }
//     if (a[i] == a[j]) {
//         if (checkP(i + 1, j - 1, dp, a)) {
//             dp[i][j] = 1;
//         } else {
//             dp[i][j] = 0;
//         }
//     } else {
//         dp[i][j] = 0;
//     }
//     if (dp[i][j] == 1) return true;
//     return false;
// }

// int Solution::solve(string A) {
//     vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
//     for (int i = 0; i < A.size(); i++) dp[i][i] = 1;
//     for (int i = 1; i < A.size(); i++) {
//         if (A[i - 1] == A[i]) {
//             dp[i - 1][i] = 1;
//         } else
//             dp[i - 1][i] = 0;
//     }
//     int index = 0;
//     for (int i = 1; i < A.size(); i++) {
//         if (checkP(0, i, dp, A)) {
//             index = i;
//         }
//     }
//     return A.size() - 1 - index;
// }
