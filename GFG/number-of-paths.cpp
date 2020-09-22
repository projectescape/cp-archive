#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        vector<vector<int>> v(a, vector<int>(b, -1));
        for (int i = 0; i < a; i++) v[i][0] = 1;
        for (int i = 0; i < b; i++) v[0][i] = 1;
        for (int i = 1; i < a; i++)
            for (int j = 1; j < b; j++) v[i][j] = v[i - 1][j] + v[i][j - 1];
        cout << v[a - 1][b - 1] << endl;
    }
    return 0;
}