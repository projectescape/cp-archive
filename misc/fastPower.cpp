#include <bits/stdc++.h>
using namespace std;

long long fastPow(int a, int b)
{
    if (b == 1)
        return a;

    long long ans = fastPow(a, b / 2) * fastPow(a, b / 2);

    if ((b & 1) == 0)
        return ans;

    return a * ans;
}

int main()
{
    int a = 5;
    int b = 2;

    cout << fastPow(a, b) << endl;
}