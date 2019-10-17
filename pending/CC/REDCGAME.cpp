#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, k, temp, sum = 0;
        cin >> a;
        cin >> k;
        vector<int> v;
        for (int i = 0; i < a; i++) {
            cin >> temp;
            if (temp <= k) {
                sum += temp;
            } else {
                sum += k;
                v.push_back(temp - k);
            }
        }
        int size = v.size();
        sort(v.begin(), v.end());

        // cout << "At line 24 sum : " << sum << " Array : ";
        // for (int i = 0; i < size; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;

        for (int i = 0; i < size; i++) {
            // cout << "At line 31 i : " << i << " sum : " << sum << " Array : ";
            // for (int i = 0; i < size; i++) {
            //     cout << v[i] << " ";
            // }
            // cout << endl;
            if (v[i] == 0) continue;
            for (int j = i + 1; j < size;) {
                if (v[j] == 0) {
                    j++;
                    continue;
                }
                if (v[i] < v[j]) {
                    v[j] -= v[i];
                    v[i] = 0;
                    break;
                } else {
                    v[i] -= v[j];
                    v[j] = 0;
                    j++;
                }
            }
        }
        // cout << "At line 55 sum : " << sum << " Array : ";
        // for (int i = 0; i < size; i++) {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        for (int i = 0; i < size; i++) {
            sum += v[i];
        }
        cout << sum << '\n';
    }
}

// For input

// 6
// 2 1
// 1 2
// 2 1
// 2 2
// 3 1
// 2 3 2
// 4 5
// 2 10 35 20
// 5 3
// 3 4 5 6 11
// 2 2
// 3 2

// Output given

// 3
// 2
// 5
// 37
// 21
// 5