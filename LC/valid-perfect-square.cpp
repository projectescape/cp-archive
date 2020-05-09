class Solution {
   public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        int mid;
        long long prod;
        for (int i = 0, j = num / 2;;) {
            if (i > j) break;
            mid = (i + j) / 2;
            prod = (long long)mid * mid;
            if (prod == num) return true;
            if (prod < num) {
                i = mid + 1;
                continue;
            }
            if (prod > num) {
                j = mid - 1;
            }
        }
        return false;
    }
};