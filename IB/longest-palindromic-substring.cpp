// Time O(n^2) space O(1)

string Solution::longestPalindrome(string A) {
    if (A.size() == 0) return "";
    string ans = "";
    int s = 0, e = 0;
    int size = 1;
    int j, k;
    for (int i = 1; i < A.size(); i++) {
        for (j = i - 1, k = i; j >= 0 && k < A.size(); j--, k++) {
            if (A[j] == A[k]) {
                if (k - j + 1 > size) {
                    size = k - j + 1;
                    s = j;
                    e = k;
                } else if (k - j + 1 == size && j < s) {
                    s = j;
                    e = k;
                }
            } else
                break;
        }
        for (j = i - 2, k = i; j >= 0 && k < A.size(); j--, k++) {
            if (A[j] == A[k]) {
                if (k - j + 1 > size) {
                    size = k - j + 1;
                    s = j;
                    e = k;
                } else if (k - j + 1 == size && j < s) {
                    s = j;
                    e = k;
                }
            } else
                break;
        }
    }
    for (j = s; j <= e; j++) ans += A[j];
    // cout<<size<<" "<<ans<<endl;
    return ans;
}

// Time O(n^2) space O(n^2), Memory Limit Exceeded
// string Solution::longestPalindrome(string A) {
//     unordered_map<int, unordered_map<int, int>> dp;
//     for (int i = 0; i < A.size(); i++) {
//         dp[i][i] = 1;
//     }
//     for (int i = 1; i < A.size(); i++) {
//         if (A[i - 1] == A[i])
//             dp[i - 1][i] = 1;
//         else
//             dp[i - 1][i] = 0;
//     }
//     for (int i = 2; i < A.size(); i++) {
//         for (int j = 0; j + i < A.size(); j++) {
//             if (A[j] != A[i + j]) {
//                 dp[j][i + j] = 0;
//             } else {
//                 dp[j][i + j] = dp[j + 1][j + i - 1];
//             }
//         }
//     }
//     string ans = "";
//     for (int i = A.size(); i >= 0; i--) {
//         for (int j = 0; j + i < A.size(); j++) {
//             if (dp[j][j + i] == 1) {
//                 for (int k = j; k <= j + i; k++) {
//                     ans += A[k];
//                 }
//                 return ans;
//             }
//         }
//     }
//     return ans;
// }
