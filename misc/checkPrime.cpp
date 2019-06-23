#include <iostream>
using namespace std;

#define ll long long

bool isPrime(ll num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll num;
    while (1) {
        cout << "Enter Number : ";
        cin >> num;
        if (isPrime(num)) {
            cout << num << " is a prime number" << endl;
        } else {
            cout << num << " is not a prime number" << endl;
        }
        cout << "Do you want to check for another number 1/0 : ";
        cin >> num;
        if (!num) {
            break;
        }
    }
}