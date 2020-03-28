#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        if (s == "") return "";
        int ans = 1, a = 0;
        bool flag = false;
        for (int i = 0; i < s.size() - 1; i++) {
            for (int j = s.size() - 1; (j > i) && (j - i + 1) > ans; j--) {
                if (s[i] == s[j]) {
                    for (int k = 1;; k++) {
                        if (i + k >= j - k) {
                            if (j - i + 1 > ans) {
                                ans = j - i + 1;
                                a = i;
                                flag = true;
                            }
                            break;
                        } else if (s[i + k] != s[j - k]) {
                            break;
                        }
                    }
                }
                if (flag) {
                    flag = false;
                    break;
                }
            }
        }
        return s.substr(a, ans);
    }
};

int main() {
    Solution obj;
    string s;
    cin >> s;
    cout << obj.longestPalindrome(s) << endl;
}