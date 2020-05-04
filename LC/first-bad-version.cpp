// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        for (int i = 0;;) {
            if (i == n) return i;
            if (isBadVersion(((long long)i + (long long)n) / 2)) {
                n = ((long long)i + (long long)n) / 2;
                continue;
            } else {
                i = (((long long)i + (long long)n) / 2) + 1;
                continue;
            }
        }
        return 1;
    }
};