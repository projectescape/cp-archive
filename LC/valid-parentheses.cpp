class Solution {
   public:
    bool isValid(string in) {
        stack<char> s;
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == '(' || in[i] == '{' || in[i] == '[') {
                s.push(in[i]);
                continue;
            }
            if (s.empty()) return false;
            if (in[i] == ')') {
                if (s.top() == '(') {
                    s.pop();
                    continue;
                } else
                    return false;
            }
            if (in[i] == '}') {
                if (s.top() == '{') {
                    s.pop();
                    continue;
                } else
                    return false;
            }
            if (in[i] == ']') {
                if (s.top() == '[') {
                    s.pop();
                    continue;
                } else
                    return false;
            }
        }
        if (!s.empty()) return false;
        return true;
    }
};