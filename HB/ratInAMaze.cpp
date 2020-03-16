#include <iostream>
using namespace std;

int number = 0;

bool ratInAMaze(char maze[][100], int i, int j, int m, int n) {
    if (i > m || j > n) {
        return false;
    }
    if (i == m && j == n) {
        number++;
        maze[i][j] = '1';
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        maze[i][j] = '0';
        return true;
    }
    if (maze[i][j] == 'X') {
        return false;
    }
    maze[i][j] = '1';

    bool right = ratInAMaze(maze, i + 1, j, m, n);
    bool left = ratInAMaze(maze, i, j + 1, m, n);
    maze[i][j] = '0';

    if (right || left) {
        return true;
    }
    return false;
}

int main() {
    char maze[][100] = {"0000", "00X0", "000X", "0X00"};
    ratInAMaze(maze, 0, 0, 3, 3);
    cout << number << endl;
}