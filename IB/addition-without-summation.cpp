int sum(int a, int b)
{
    if (b == 0)
        return a;

    int carry = (a & b) << 1;
    a = a ^ b;

    if (carry == 0)
        return a;

    return sum(a, carry);
}

int Solution::addNumbers(int A, int B)
{

    return sum(A, B);
}
