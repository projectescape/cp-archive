#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int a, b, temp;
    cin >> a;
    cin >> b;
    // cout << a << " " << b << endl;

    for (int i = 0; i < a; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < b && i < a; i++) {
        temp = i;
        for (int j = i; j < a; j++) {
            if (v[j] > v[temp]) temp = j;
        }
        // cout << "Swapping" << v[i] << " and " << v[temp] << endl;
        if (i == temp) {
            b++;
            continue;
        }
        swap(v[i], v[temp]);
    }

    for (int i = 0; i < a; i++) {
        cout << v[i] << " ";
    }
    return 0;
}