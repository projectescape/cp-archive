#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, prev = -1, l = -1, flag = 1;
    cin >> T;
    string s;
    while (T--) {
        prev = -1, l = -1;
        flag = 1;
        cin >> s;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '.') continue;
            l = i - s[i] + '0';
            if (l < 0) l = 0;
            if (prev != -1) {
                if (l <= prev) {
                    flag = 0;
                    // cout<<"At i : "<<i<<" prev : "<<prev<<" ";
                    cout << "unsafe\n";

                    break;
                }
            }
            prev = i + s[i] - '0';
            // cout<<"At i : "<<i<<" prev : "<<prev<<endl;
            if (prev >= size) prev = size - 1;
        }
        if (flag) cout << "safe\n";
    }
    return 0;
}
