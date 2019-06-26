#include <iostream>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ll a, b, c;
    cout << "Enter 1st number : ";
    cin >> a;
    cout << "Enter 2nd number : ";
    cin >> b;
    c = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is " << c << endl;
}