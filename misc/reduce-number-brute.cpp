// DO NOT FOLLOW THIS!!!
// reduce-number-dynamic is better approach
// Minimum no ofsteps to reduce number to 1, allowed operation - (/3,/2,-1)

#include <bits/stdc++.h>
using namespace std;

const int inf = (int)1e9;
int reduce(int n, int steps = 0) {
    int ans = inf, temp = 0;
    if (n == 1) {
        return steps;
    }
    if (n % 3 == 0) {
        ans = reduce(n / 3, steps + 1);
    }
    if (n % 2 == 0) {
        temp = reduce(n / 2, steps + 1);
        if (temp < ans) {
            ans = temp;
        }
    }
    temp = reduce(n - 1, steps + 1);
    if (temp < ans) {
        ans = temp;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << reduce(n) << endl;
}