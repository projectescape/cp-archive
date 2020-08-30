int Solution::cntBits(vector<int> &A) {
    long long ans = 0, n = A.size();
    vector<int> v(32, 0);
    for (long long i = 0; i < A.size(); i++) {
        for (int j = 0; j < 32; j++) {
            if (A[i] & (1 << j))
                v[j]++;
        }
    }
    for (int i = 0; i < 32; i++) {
        ans += ((n - v[i]) * v[i]);
    }
    ans *= 2;
    return ans % 1000000007;
}
