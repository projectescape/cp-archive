int Solution::sqrt(int x) {
    int start = 1, ans;
    long end = x;
    while (start <= end) {
        long mid = end + (start - end) / 2;

        if (mid * mid == x)
            return mid;

        if (mid * mid < x) {
            start = mid + 1;
            ans = mid;
        } else
            end = mid - 1;
    }
    return ans;
}
