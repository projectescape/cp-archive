// https://www.codechef.com/problems/GRAYSC

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    if (n >= 130) {
        cout << "Yes";
        return 0;
    }
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (ll i = 0; i < n; i++)
        for (ll j = i + 1; j < n; j++)
            for (ll k = j + 1; k < n; k++)
                for (ll l = k + 1; l < n; l++) {
                    if ((arr[i] ^ arr[j] ^ arr[k] ^ arr[l]) == 0) {
                        cout << "Yes";
                        return 0;
                    }
                }

    cout << "No";
    return 0;
}
