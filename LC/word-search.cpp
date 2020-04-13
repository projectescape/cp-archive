#include <bits/stdc++.h>
using namespace std;

bool searchWord(vector<vector<char>> &board, vector<vector<bool>> &dp, string &word, int i, int j, int &m, int &n, int index) {
    if (index == word.size()) return true;
    if (i >= m || i < 0 || j >= n || j < 0 || word[index] != board[i][j] || dp[i][j] == false) return false;

    dp[i][j] = false;

    if (searchWord(board, dp, word, i + 1, j, m, n, index + 1)) return true;
    if (searchWord(board, dp, word, i - 1, j, m, n, index + 1)) return true;
    if (searchWord(board, dp, word, i, j + 1, m, n, index + 1)) return true;
    if (searchWord(board, dp, word, i, j - 1, m, n, index + 1)) return true;

    dp[i][j] = true;
    return false;
}

class Solution {
   public:
    bool exist(vector<vector<char>> &board, string word) {
        if (word.size() == 0) return true;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> dp(m, vector<bool>(n, true));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (searchWord(board, dp, word, i, j, m, n, 0)) {
                        return true;
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