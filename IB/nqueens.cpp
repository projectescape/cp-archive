void sol(vector<vector<string>> &ans, vector<string> &board, int &A, int row) {
    if (row == A) {
        ans.push_back(board);
        return;
    }
    bool flag;
    for (int col = 0; col < A; col++) {
        flag = true;
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            for (int i = row - 1, j = col + 1; i >= 0 && j < A; i--, j++) {
                if (board[i][j] == 'Q') {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            board[row][col] = 'Q';
            sol(ans, board, A, row + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int A) {
    string temp = "";
    for (int i = 0; i < A; i++) temp += '.';
    vector<string> board(A, temp);
    vector<vector<string>> ans;
    if (A == 0) return ans;
    for (int i = 0; i < A; i++) {
        board[0][i] = 'Q';
        sol(ans, board, A, 1);
        board[0][i] = '.';
    }
    return ans;
}
