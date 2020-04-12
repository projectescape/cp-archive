#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> dp(m, vector<bool>(n, true));
                    dp[i][j] = false;
                    cout << word[0] << " found at " << i << ", " << j << endl;
                    int a = i, b = j;
                    for (int i = 1; i <= word.size(); i++) {
                        if (i == word.size()) return true;
                        if (a + 1 < m && dp[a + 1][b]) {
                            if (board[a + 1][b] == word[i]) {
                                a++;
                                cout << word[i] << " found at " << a << ", " << b << endl;
                                dp[a][b] = false;
                                continue;
                            }
                        }
                        if (a - 1 >= 0 && dp[a - 1][b]) {
                            if (board[a - 1][b] == word[i]) {
                                a--;
                                cout << word[i] << " found at " << a << ", " << b << endl;
                                dp[a][b] = false;
                                continue;
                            }
                        }
                        if (b + 1 < n && dp[a][b + 1]) {
                            if (board[a][b + 1] == word[i]) {
                                b++;
                                cout << word[i] << " found at " << a << ", " << b << endl;
                                dp[a][b] = false;
                                continue;
                            }
                        }
                        if (b - 1 >= 0 && dp[a][b - 1]) {
                            if (board[a][b - 1] == word[i]) {
                                b--;
                                cout << word[i] << " found at " << a << ", " << b << endl;
                                dp[a][b] = false;
                                continue;
                            }
                        }
                        break;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
    string word = "AAB";
    Solution obj;
    cout << obj.exist(board, word) << endl;
}