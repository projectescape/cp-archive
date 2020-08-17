void mult(string &s, int n) {
    int carry = 0, temp;
    for (int i = 0; i < s.size(); i++) {
        temp = (s[i] - '0') * 2 + carry;
        carry = 0;
        if (temp > 9) {
            carry = 1;
            temp -= 10;
        }
        s[i] = temp + '0';
    }
    if (carry) s.push_back('1');
}

int Solution::power(string A) {
    if (A == "0") return 1;
    reverse(A.begin(), A.end());
    string temp = "2";
    while (temp.size() <= A.size()) {
        if (temp == A) return 1;
        mult(temp, 2);
    }
    return 0;
}