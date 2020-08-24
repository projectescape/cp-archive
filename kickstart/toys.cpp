#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        vector<int> e(N), r(N);
        for (int i = 0; i < N; i++) {
            cin >> e[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> r[i];
        }
    }
    return 0;
}