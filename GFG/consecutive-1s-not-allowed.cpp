class Solution {
   public:
    ll countStrings(int n) {
        vector<ll> zero(n, 0);
        vector<ll> one(n, 0);
        zero[0] = one[0] = 1;
        if (n >= 2) {
            zero[1] = 2;
            one[1] = 1;
        }
        for (int i = 2; i < n; i++) {
            zero[i] = (zero[i - 1] % 1000000007 + one[i - 1] % 1000000007) % 1000000007;
            one[i] = zero[i - 1];
        }
        return (zero[n - 1] % 1000000007 + one[n - 1] % 1000000007) % 1000000007;
    }
};