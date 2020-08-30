int Solution::singleNumber(const vector<int> &A) {
    vector<long long> n(32, 0);
    for (auto num : A) {
        for (long long i = 0; i < 32; i++) {
            n[i] += (num & (1 << i));
        }
    }
    int ans = 0;
    for (long long i = 0; i < 32; i++) {
        n[i] %= 3;
        if (n[i])
            ans = ans | (1 << i);
    }
    return ans;
}
