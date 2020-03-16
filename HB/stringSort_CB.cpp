// https://hack.codingblocks.com/contests/c/262/103

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long

class compar {
   public:
    bool operator()(string a, string b) {
        if (a.length() > b.length()) {
            if (a.find(b) == 0) {
                return true;
            }
        } else if (b.find(a) == 0) {
            return false;
        }
        return a < b;
    }
} obj;

int main() {
    ll n;
    cin >> n;
    string temp;
    vector<string> vec;
    vec.reserve(n);
    for (ll i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), obj);
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *(it) << endl;
    }
}