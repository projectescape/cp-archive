// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

#include <bits/stdc++.h>
using namespace std;

string reverse(string a) {
    vector<string> v;
    string temp = "", ans = "";
    int l = a.length();
    for (int i = 0; i < l; i++) {
        if (a[i] == '.' || i == l - 1) {
            if (a[i] != '.') temp += a[i];
            v.push_back(temp);
            temp = "";
            continue;
        }
        temp += a[i];
    }
    int s = v.size();
    for (int i = s - 1; i >= 0; i--) {
        ans += v[i];
        if (i != 0) {
            ans += '.';
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << reverse(a) << endl;
    }
    //code
    return 0;
}