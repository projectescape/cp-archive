string helper(string &a, int s, int e) {
    string ans = "", temp;
    int mul, sNew, eNew, bracket;

    for (int i = s; i < e; i++) {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
            ans += a[i];
        } else {
            temp = "";
            for (; a[i] != '['; i++) {
                temp += a[i];
            }
            bracket = 1;
            sNew = ++i;
            for (; bracket > 1 || a[i] != ']'; i++) {
                if (a[i] == '[') bracket++;
                if (a[i] == ']') bracket--;
            }
            eNew = i;
            mul = stoi(temp);
            temp = helper(a, sNew, eNew);
            while (mul--) ans += temp;
        }
    }
    return ans;
}

class Solution {
   public:
    string decodeString(string s) {
        return helper(s, 0, s.size());
    }
};