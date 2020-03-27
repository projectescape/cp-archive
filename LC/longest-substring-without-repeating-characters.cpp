#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        // if (s.size() == 1) return 1;
        int occ[128] = {0};
        int ans = 0, curr = 0;
        if ((s[0]) >= 0 && (s[0]) < 128) {
            occ[s[0]] += 1;
        }
        for (int i = 0, j = 1; i < s.size(); i++) {
            if ((s[i]) >= 0 && (s[i]) < 128) {
                curr++;
            } else {
                continue;
            }
            for (; j < s.size(); j++) {
                if ((s[j]) >= 0 && (s[j]) < 128) {
                    occ[s[j]] += 1;
                } else {
                    continue;
                }
                cout << "i = " << i << ", j = " << j << endl;
                cout << "occ[" << s[i] << "] = " << occ[s[i]] << ", occ[" << s[j] << "] = " << occ[s[j]] << endl;
                if (occ[s[j]] == 2) {
                    ans = max(ans, curr);
                    curr--;
                    occ[s[i]] -= 1;
                    occ[s[j]] -= 1;
                    break;
                } else {
                    curr++;
                }
            }
            ans = max(ans, curr);
            curr--;
        }
        ans = max(ans, curr);
        return ans;
    }
};

int main() {
    cout << "Here" << endl;
    Solution obj;
    string s = "aaaaaaaaabca";
    int ans = obj.lengthOfLongestSubstring(s);
    cout << "Ans = " << ans << endl;
}
