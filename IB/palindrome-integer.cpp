int Solution::isPalindrome(int A) {
    string num = to_string(A);
    for (int i = 0; i <= num.size() / 2; i++) {
        if (num[i] != num[num.size() - 1 - i]) return false;
    }
    return true;
}
