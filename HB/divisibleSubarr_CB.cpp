// https://hack.codingblocks.com/practice/p/364/266

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long

int main(int argc, char const *argv[]) {
    ll cases;
    cin >> cases;
    while (cases--) {
        ll size, ans = 0;
        cin >> size;
        vector<ll> arr(size), freq(size, 0);
        for (ll i = 0; i < size; i++) {
            cin >> arr[i];
            while (arr[i] < 0) {
                arr[i] += size;
            }
            if (i > 0) {
                arr[i] += arr[i - 1];
            }
            arr[i] %= size;
            freq[arr[i]]++;
        }
        // for(ll i=0;i<size;i++){
        //     cout<<endl<<arr[i]<<" ";
        // }
        // for(ll i=0;i<size;i++){
        //     cout<<endl<<freq[i]<<" ";
        // }
        for (ll i = 0; i < size; i++) {
            if (i == 0) {
                ans += (freq[i] + 1) * (freq[i]) / 2;
                continue;
            }
            ans += freq[i] * (freq[i] - 1) / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
