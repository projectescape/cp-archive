string Solution::multiply(string A, string B) {
    if (A == "0" || B == "0") return "0";
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    for (int i = A.size() - 1; i >= 0 && A[i] == '0'; i--) A.pop_back();
    for (int i = B.size() - 1; i >= 0 && B[i] == '0'; i--) B.pop_back();
    if (!A.size() || !B.size()) return "0";
    string ans = "0", temp;
    int carry = 0, curr;
    for (int i = 0, j; i < B.size(); i++) {
        temp = "";
        for (j = 0; j < i; j++) temp.push_back('0');
        carry = 0;
        for (j = 0; j < A.size(); j++) {
            curr = (A[j] - '0') * (B[i] - '0') + carry;
            temp.push_back(curr % 10 + '0');
            carry = curr / 10;
        }
        if (carry) {
            temp.push_back(carry + '0');
        }
        carry = 0;
        for (j = 0; j < min(temp.size(), ans.size()); j++) {
            curr = temp[j] + ans[j] - '0' - '0' + carry;
            ans[j] = curr % 10 + '0';
            carry = curr / 10;
        }
        for (; j < ans.size(); j++) {
            curr = ans[j] - '0' + carry;
            ans[j] = curr % 10 + '0';
            carry = curr / 10;
        }

        for (; j < temp.size(); j++) {
            curr = temp[j] - '0' + carry;
            ans.push_back(curr % 10 + '0');
            carry = curr / 10;
        }
        if (carry) {
            ans.push_back(carry + '0');
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
