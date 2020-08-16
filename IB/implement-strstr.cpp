int Solution::strStr(const string B, const string A) {
    if (B.size() < A.size()) return -1;
    for (int i = 0; i + A.size() - 1 < B.size(); i++) {
        if (B[i] == A[0] && B[i + A.size() - 1] == A[A.size() - 1]) {
            bool flag = true;
            for (int j = 0; j < A.size(); j++) {
                if (B[i + j] != A[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
    }
    return -1;
}