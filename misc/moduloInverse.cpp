#include <iostream>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll x, y, GCD;
// ax + by = gcd(a,b);
// we get x,y from extended euclid
void extendedEuclid(ll a, ll b) {
    // Base Case
    if (b == 0) {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

    // Recursive
    extendedEuclid(b, a % b);
    ll cX = y;
    ll cY = x - (a / b) * y;
    x = cX;
    y = cY;
    return;
}

ll moduloInverse(ll a, ll m) {
    if (gcd(a, m) != 1) {
        cout << "modulo inverse does not exist" << endl;
        return 0;
    }
    extendedEuclid(a, m);
    return (x + m) % m;
}

int main() {
    cout << moduloInverse(6, 8) << endl;
}