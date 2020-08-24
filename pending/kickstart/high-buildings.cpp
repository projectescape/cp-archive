#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, A, B, C, j, k, turn = 0;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N >> A >> B >> C;
        if (A + B - C > N ||
            (C != N && !(A > C || B > C))) {
            cout << "Case #" << i << ": "
                 << "IMPOSSIBLE" << endl;
            continue;
        }
        // if (N == 1) {
        //     cout << "Case #" << i << ": " << 1 << endl;
        //     continue;
        // }
        vector<int> ans(N, 1);
        j = 0, k = N - 1;
        for (; j < A - C; j++) {
            ans[j] = j + (N - A + C);
        }
        for (int i = 0; i < B - C; i++, k--) {
            ans[k] = i + (N - B + C);
        }
        if (j == 0) {
            ans[j] = N;
            j++;
            C--;
            turn = 1;
        }
        if (k == N - 1) {
            ans[k] = N;
            k--;
            C--;
            turn = 0;
        }
        while (C > 0) {
            if (turn == 0)
                ans[j++] = N;
            else
                ans[k--] = N;
            turn = !turn;
            C--;
        }
        cout << "Case #" << i << ": ";
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}