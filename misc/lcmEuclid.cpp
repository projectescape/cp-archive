#include <iostream>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll c = gcd(a, b);
    return a * b / c;
}

int main() {
    ll a, b, c;
    cout << "Enter 1st number : ";
    cin >> a;
    cout << "Enter 2nd number : ";
    cin >> b;
    c = lcm(a, b);
    cout << "LCM of " << a << " and " << b << " is " << c << endl;
}