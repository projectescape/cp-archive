// Minimum no ofsteps to reduce number to 1, allowed operation - (/3,/2,-1)

#include <bits/stdc++.h>
using namespace std;

int memo[1000];
const int inf = (int)1e9;

int reduceDP(int n) {
    memo[0] = memo[1] = 0;
    memo[3] = memo[2] = 1;

    for (int i = 4; i <= n; i++) {
        int q1 = inf;
        int q2 = inf;
        int q3 = inf;
        if (i % 3 == 0) q1 = 1 + memo[i / 3];
        if (i % 2 == 0) q2 = 1 + memo[i / 2];
        q3 = 1 + memo[i - 1];
        memo[i] = min(q1, min(q2, q3));
    }
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    // for (int i = 0; i <= n; i++) {
    //     memo[i] = -1;
    // }
    fill(memo, memo + n + 1, -1);
    cout << reduceDP(n) << endl;
}