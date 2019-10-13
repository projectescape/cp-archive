#include <bits/stdc++.h>
using namespace std;

long long fastPow(long long a, long long b)
{
    if (b == 1)
        return a;

    if (b & 1 == 0)
        return fastPow(a, b / 2) * fastPow(a, b / 2);
    return a * fastPow(a, b / 2) * fastPow(a, b / 2);
}

int main()
{
    long long a = 2;
    long long b = 3;

    cout << fastPow(2, 3) << endl;
}