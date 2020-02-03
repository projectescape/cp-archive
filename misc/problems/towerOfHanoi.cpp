#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char s, char d, char h)
{
    if (!n)
        return;

    hanoi(n - 1, s, h, d);

    cout << "Move " << n << " disk from " << s << " to " << d << endl;

    hanoi(n - 1, h, d, s);
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
}