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

int main() {
    ll a, b;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    extendedEuclid(a, b);
    cout << x << " , " << y << endl;
}