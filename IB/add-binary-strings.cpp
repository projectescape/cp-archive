string Solution::addBinary(string A, string B) {
    bool carry = false;
    string ans = "";
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    for (int i = 0; i < A.size() || i < B.size() || carry; i++) {
        if (i < A.size() && i < B.size()) {
            if (carry) {
                if (A[i] == '0' && B[i] == '0') {
                    ans += '1';
                    carry = false;
                } else if (A[i] == '0' && B[i] == '1') {
                    ans += '0';
                } else if (A[i] == '1' && B[i] == '0') {
                    ans += '0';
                } else {
                    ans += '1';
                }
            } else {
                if (A[i] == '0' && B[i] == '0') {
                    ans += '0';
                } else if (A[i] == '0' && B[i] == '1') {
                    ans += '1';
                } else if (A[i] == '1' && B[i] == '0') {
                    ans += '1';
                } else {
                    ans += '0';
                    carry = true;
                }
            }
        } else if (i < A.size()) {
            if (carry) {
                if (A[i] == '0') {
                    ans += "1";
                    carry = false;
                } else {
                    ans += "0";
                }
            } else {
                ans += A[i];
            }
        } else if (i < B.size()) {
            if (carry) {
                if (B[i] == '0') {
                    ans += '1';
                    carry = false;
                } else {
                    ans += '0';
                }
            } else {
                ans += B[i];
            }
        } else {
            ans += "1";
            carry = false;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
