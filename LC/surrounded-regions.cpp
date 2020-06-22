void borderBfs(vector<vector<char>> &board, int i, int j, int &m, int &n) {
    board[i][j] = '1';
    if (i - 1 >= 0 && board[i - 1][j] == 'O') {
        borderBfs(board, i - 1, j, m, n);
    }
    if (i + 1 < m && board[i + 1][j] == 'O') {
        borderBfs(board, i + 1, j, m, n);
    }
    if (j - 1 >= 0 && board[i][j - 1] == 'O') {
        borderBfs(board, i, j - 1, m, n);
    }
    if (j + 1 < n && board[i][j + 1] == 'O') {
        borderBfs(board, i, j + 1, m, n);
    }
}
void bfs(vector<vector<char>> &board, int i, int j, int &m, int &n) {
    board[i][j] = 'X';
    if (i - 1 >= 0 && board[i - 1][j] == 'O') {
        bfs(board, i - 1, j, m, n);
    }
    if (i + 1 < m && board[i + 1][j] == 'O') {
        bfs(board, i + 1, j, m, n);
    }
    if (j - 1 >= 0 && board[i][j - 1] == 'O') {
        bfs(board, i, j - 1, m, n);
    }
    if (j + 1 < n && board[i][j + 1] == 'O') {
        bfs(board, i, j + 1, m, n);
    }
}

class Solution {
   public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if (m < 2) return;
        int n = board[0].size();
        if (n < 2) return;
        int i, j;
        for (i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                borderBfs(board, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O') {
                borderBfs(board, i, n - 1, m, n);
            }
        }
        for (i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                borderBfs(board, 0, i, m, n);
            }
            if (board[m - 1][i] == 'O') {
                borderBfs(board, m - 1, i, m, n);
            }
        }
        for (i = 1; i < m - 1; i++) {
            for (j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O' && (board[i - 1][j] == 'X' || board[i + 1][j] == 'X' || board[i][j - 1] == 'X' || board[i][j + 1] == 'X')) {
                    bfs(board, i, j, m, n);
                }
            }
        }
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (board[i][j] == '1') board[i][j] = 'O';
    }
};