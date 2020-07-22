#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, temp;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp = matrix[i - 1][j];
                if (j - 1 >= 0) {
                    temp = max(temp, matrix[i - 1][j - 1]);
                }
                if (j + 1 < n) {
                    temp = max(temp, matrix[i - 1][j + 1]);
                }
                matrix[i][j] += temp;
            }
        }
        temp = INT_MIN;
        for (int i = 0; i < n; i++) {
            temp = max(temp, matrix[n - 1][i]);
        }
        cout << temp << endl;
    }
    return 0;
}