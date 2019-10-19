#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

int gcd(int a, int b)

{
    if (b == 0)
        return a;
    int x = gcd(b, a % b);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int size = s.size();
        if (size < 2) {
            cout << s << "\n";
            continue;
        }
        int index = -1;
        char cmax = '0';
        for (int i = 0; i < size; i++) {
            if (i == 1) {
                if (s[i] == '0') {
                    index = 0;
                    break;
                }
            }
            if (s[i] > cmax) {
                cmax = s[i];
                index = i;
            }
            if (i > 0 && s[i] == '0') break;
        }
        for (int i = 0; i < size; i++) {
            if (i == 1 && index == 0 && s[i] == '0') {
                while (s[i] == '0') i++;
                i--;
                continue;
            }
            if (index == i) continue;
            cout << s[i];
        }
        cout << "\n";
    }

    return 0;
}
