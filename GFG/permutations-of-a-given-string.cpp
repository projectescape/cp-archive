// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include <bits/stdc++.h>
using namespace std;

void permute(vector<string> &v, string a, int l, int i = 0) {
    if (i == l - 1) {
        v.push_back(a);
    }
    for (int j = i; j < l; j++) {
        swap(a[i], a[j]);
        permute(v, a, l, i + 1);

        swap(a[i], a[j]);
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> v;
        string a;
        cin >> a;
        int l = a.length();
        permute(v, a, l);
        // cout << v.size() << endl;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    //code
    return 0;
}