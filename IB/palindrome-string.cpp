int Solution::isPalindrome(string A) {
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    string a = "";
    for (auto i : A) {
        if ((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')) {
            a += i;
        }
    }
    string b = a;
    reverse(a.begin(), a.end());
    return a == b ? 1 : 0;
}
