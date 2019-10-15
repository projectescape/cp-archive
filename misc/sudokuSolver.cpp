#include <bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int num) {
    for (int k = 0; k < n; k++) {
        if (mat[i][k] == num || mat[k][j] == num)
            return false;
    }
    int s = sqrt(n);
    int sx = (i / s) * s;
    int sy = (j / s) * s;

    for (int x = sx; x < sx + s; x++) {
        for (int y = sy; y < sy + s; y++) {
            if (mat[x][y] == num) return false;
        }
    }

    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n) {
    if (i == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << "  ";
            }
            cout << "\n";
        }
        return true;
    }

    if (j == n)
        return solveSudoku(mat, i + 1, 0, n);

    if (mat[i][j] != 0)
        return solveSudoku(mat, i, j + 1, n);

    for (int num = 1; num < 10; num++) {
        if (canPlace(mat, i, j, n, num)) {
            mat[i][j] = num;
            bool solved = solveSudoku(mat, i, j + 1, n);
            if (solved)
                return true;
        }
    }

    mat[i][j] = 0;
    return false;
}

int main() {
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    solveSudoku(mat, 0, 0, 9);
}