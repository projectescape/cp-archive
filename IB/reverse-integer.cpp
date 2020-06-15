int Solution::reverse(int A) {
    bool isNegative = A < 0;
    long long B = 0;
    A = abs(A);
    while (A) {
        B *= 10;
        B += A % 10;
        A /= 10;
    }
    if (isNegative) B *= -1;
    if (B < INT_MIN)
        return 0;

    if (B > INT_MAX)
        return 0;

    return B;
}
