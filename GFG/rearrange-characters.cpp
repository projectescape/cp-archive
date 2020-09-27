#include <bits/stdc++.h>
using namespace std;

class comp {
   public:
    bool operator()(pair<char, int> &a, pair<char, int> &b) {
        return a.second < b.second;
    }
};

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        unordered_map<char, int> m;
        for (auto &i : s) m[i]++;
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> p;
        for (auto &i : m) p.push(i);
        int ans = 1;
        pair<char, int> temp1, temp2;
        while (!p.empty()) {
            temp1 = p.top();
            p.pop();
            temp1.second--;
            if (temp1.second != 0) {
                if (p.empty()) {
                    ans = 0;
                    break;
                }
                temp2 = p.top();
                p.pop();
                temp2.second--;
                p.push(temp1);
                if (temp2.second != 0) {
                    p.push(temp2);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}