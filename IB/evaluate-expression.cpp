int Solution::evalRPN(vector<string> &A) {
    stack<string> s;
    int a, b;
    for (auto i : A) {
        if (i == "+") {
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
            s.pop();
            s.push(to_string(a + b));
        } else if (i == "-") {
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
            s.pop();
            s.push(to_string(a - b));
        } else if (i == "*") {
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
            s.pop();
            s.push(to_string(a * b));
        } else if (i == "/") {
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
            s.pop();
            s.push(to_string(a / b));
        } else {
            s.push(i);
        }
    }
    return stoi(s.top());
}
