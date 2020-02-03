#include <bits/stdc++.h>
using namespace std;
// reduce-number-dynamic is better approach
// Minimum no ofsteps to reduce number to 1, allowed operation - (/3,/2,-1)

int memo[1000];
const int inf = (int)1e9;
int reduce(int n) {
    if (n == 1) {
        return 0;
    }
    if (memo[n] != -1) {
        return memo[n];
    }

    int q1, q2, q3;
    q1 = q2 = q3 = inf;
    if (n % 3 == 0) {
        q1 = 1 + reduce(n / 3);
    }
    if (n % 2 == 0) {
        q2 = 1 + reduce(n / 2);
    }
    q3 = 1 + reduce(n - 1);
    memo[n] = min(q1, min(q2, q3));
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    // for (int i = 0; i <= n; i++) {
    //     memo[i] = -1;
    // }
    fill(memo, memo + n + 1, -1);
    cout << reduce(n) << endl;
}