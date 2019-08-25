#include <bits/stdc++.h>
using namespace std;

void primeSieve(long long *p, long long n) {
    p[0] = p[1] = 0;
    p[2] = 1;
    for (long long i = 3; i <= n; i += 2) {
        p[i] = 1;
    }
    for (long long i = 3; i <= n; i += 2) {
        if (p[i]) {
            for (long long j = i * i; j <= n; j += 2 * i) {
                p[j] = 0;
            }
        }
    }
    return;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        long long L, R, ans = 0, alice = 0, bob = 0, primes = 0, x = 0;
        cin >> L >> R;
        long long N = sqrtl(R);
        long long p[N + 1] = {0};
        primeSieve(p, N);
        // vector<long long> v;
        // N++;

        for (long long j = L; j <= R; j++) {
            for (int i = x; i <= sqrtl(j); i++) {
                if (p[i]) {
                    // v.push_back(i);
                    primes++;
                }
            }
            x++;
            alice = pow(2, primes - 1) + 1;
            bob = alice;
            if (j % 2 == 0)
                bob++;
            else
                alice++;
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
}

// for (long long i = L; i <= R; i++) {
//     alice = 0, bob = 0;
//     for (long long j = 1; j <= i / 2; j = j + 2) {
//         if (i % j == 0) alice++;
//     }
//     if (i % 2 == 0) {
//         for (long long j = 2; j <= i / 2; j = j + 2) {
//             if (i % j == 0) bob++;
//         }
//         bob++;
//     } else {
//         alice++;
//     }
//     cout << "alice = " << alice << endl;
//     cout << "bob = " << bob << endl;
//     cout << "llabs(alice - bob) = " << llabs(alice - bob) << endl;
//     if (llabs(alice - bob) <= 2) ans++;
// }