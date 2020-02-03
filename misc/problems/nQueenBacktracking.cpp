#include <iostream>
#include <string>

using namespace std;

bool canPlace(int mat[0][10], int i, int j, int n) {
    for (int k = i - 1; k >= 0; k--) {
        if (mat[k][j] == 1) {
            // cout<<"INSIDE COL"<<endl;
            return false;
        }
    }
    for (int k = 0; k < n; k++) {
        if (mat[i][k] == 1) {
            // cout<<"INSIDe ROW"<<endl;
            return false;
        }
    }
    for (int k = 1; (i - k) >= 0 && (j - k) >= 0; k++) {
        if (mat[i - k][j - k] == 1) {
            // cout<<"INSIDE LEFT DIAGONAL"<<endl;
            return false;
        }
    }
    for (int k = 1; (i - k) >= 0 && (j + k) < n; k++) {
        if (mat[i - k][j + k] == 1) {
            // cout<<"INSIDE RIGHT DIAGONAL"<<endl;
            return false;
        }
    }

    return true;
}

bool nQueen(int mat[][10], int i, int n) {
    // cout<<i<<endl;

    if (i == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        // Print here
        return false;
    }
    bool temp;
    for (int x = 0; x < n; x++) {
        if (canPlace(mat, i, x, n)) {
            // cout<<"INSIDE"<<i<<endl;
            mat[i][x] = 1;
            temp = nQueen(mat, i + 1, n);
            //   mat[i][x]=0;
        }
        if (temp) {
            return true;
        } else {
            mat[i][x] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    n = 4;
    int mat[10][10] = {0};
    nQueen(mat, 0, n);
}
