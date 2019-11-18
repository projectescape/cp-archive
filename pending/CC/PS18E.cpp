#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int a, b, n, odd = 0, even = 0;
        cin >> n;
        int arr[n + 1];
        memset(arr, 0, sizeof arr);
        arr[1] = 1;
        odd++;
        n--;
        queue<pair<int, int>> q;
        while (n--) {
            cin >> a;
            cin >> b;
            if (arr[a] != 0) {
                if (arr[a] == 1) {
                    even++;
                    arr[b] = 2;
                } else {
                    odd++;
                    arr[b] = 1;
                }
            } else if (arr[b] != 0) {
                if (arr[b] == 1) {
                    even++;
                    arr[a] = 2;
                } else {
                    odd++;
                    arr[a] = 1;
                }
            } else {
                q.push({a, b});
            }
        }
        while (!q.empty()) {
            a = q.front().first;
            b = q.front().second;
            if (arr[a] != 0) {
                if (arr[a] == 1) {
                    even++;
                    arr[b] = 2;
                } else {
                    odd++;
                    arr[b] = 1;
                }
            } else if (arr[b] != 0) {
                if (arr[b] == 1) {
                    even++;
                    arr[a] = 2;
                } else {
                    odd++;
                    arr[a] = 1;
                }
            } else {
                q.push({a, b});
            }
            q.pop();
        }
        if (odd < even)
            cout << odd * 2 + even * 1 << endl;
        else
            cout << odd * 1 + even * 2 << endl;
    }
    return 0;
}
