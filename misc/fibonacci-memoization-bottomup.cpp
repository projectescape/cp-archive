// DO NOT FOLLOW THIS!!!
// fibonacci-dynamic-topdown is better approach, less function memory overhead

#include <bits/stdc++.h>
using namespace std;

long long memo[1000];

long long fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }
    long long ans = fib(n - 1) + fib(n - 2);
    memo[n] = ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    long long ans = fib(n);
    cout << ans << endl;
}