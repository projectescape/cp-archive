class Solution {
   public:
    string removeKdigits(string num, int k) {
        if (num.size() == 0 || num.size() == k) return "0";
        stack<char> s;
        s.push(num[0]);
        for (int i = 1; i < num.size(); i++) {
            while (k != 0 && !s.empty() && s.top() > num[i]) {
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        string ans = "";
        while (k--) {
            s.pop();
        }
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        while (ans.size() > 0 && ans[0] == '0') {
            ans.erase(0, 1);
        }
        if (ans.size() == 0) return "0";
        return ans;
    }
};