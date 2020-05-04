class Solution {
   public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;

        int p = 0;
        while ((N % (long long)(pow(2, p))) != N) p++;
        long long ans = 0;
        for (int i = 0; i < p; i++) {
            ans *= 2;
            ans += 1;
        }
        return abs(ans - N);
    }
};