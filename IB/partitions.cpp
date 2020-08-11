int Solution::solve(int A, vector<int> &B) {
    int total = 0;
    for (auto i : B) total += i;
    if (total % 3 != 0) return 0;
    int ans = 0;
    total /= 3;
    int curr = 0, curr2;
    for (int i = 0; i < A - 2; i++) {
        curr += B[i];
        if (curr == total) {
            curr2 = 0;
            for (int j = i + 1; j < A - 1; j++) {
                curr2 += B[j];
                if (curr2 == total) ans++;
            }
        }
    }

    return ans;
}
