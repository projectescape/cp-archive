int Solution::solve(int a, int b, int c) {
    if (a == 0 || b == 0) return 0;
    int ab = min(a, b);
    int ans = 0;
    if (c < ab) {
        a -= c;
        b -= c;
        ab -= c;
        ans += c;
        c = (a + b) / 3;
        ans += min(a, min(b, c));
    } else {
        return ab;
    }
    return ans;
}
