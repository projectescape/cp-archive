#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, k, temp, b;
        cin >> a >> k;
        int sum = 0;
        vector<int> v;
        for (int i = 0; i < a; i++) {
            cin >> temp;
            if (temp <= k)
                sum += k;
            else {
                b = temp % k;
                if (b != 0) {
                    sum += b;
                    v.push_back(temp / k);
                } else {
                    sum += k;
                    v.push_back((temp / k) - 1);
                }
            }
        }
        int size = v.size();
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < size - 1; i++) {
            if (v[i] == 0) continue;
            for (int j = i + 1; j < size && v[i] > 0; j++) {
                if (v[j] == 0) {
                    continue;
                }
                if (v[i] > v[j]) {
                    v[i] = v[i] - v[j];
                    v[j] = 0;
                } else {
                    v[j] = v[j] - v[i];
                    v[i] = 0;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            sum += (v[i] * k);
        }
        cout << sum << '\n';
    }
}