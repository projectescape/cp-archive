int divideBy2(string A)
{
    if (A.size() == 1 && A[0] == '2')
    {
        return 1;
    }
    int curr = 0;
    string s;
    for (int i = 0; (i < A.size()); i++)
    {
        curr = curr * 10 + A[i] - '0';
        if (!((s.size() == 0) && (curr / 2 == 0)))
        {
            s += (curr / 2 + '0');
        }
        curr = curr % 2;
    }
    if (curr != 0)
        return 0;
    return divideBy2(s);
}

int Solution::power(string A)
{
    if (A.size() == 0)
        return 0;
    if (A.size() == 1 && (A[0] == '0'))
        return 0;
    return divideBy2(A);
}
