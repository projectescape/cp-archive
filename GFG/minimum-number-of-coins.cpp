#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    while (x--) {
        int n;
        cin >> n;
        while (n) {
            if (n >= 2000) {
                cout << "2000 ";
                n -= 2000;
            } else if (n >= 500) {
                cout << "500 ";
                n -= 500;
            } else if (n >= 200) {
                cout << "200 ";
                n -= 200;
            } else if (n >= 100) {
                cout << "100 ";
                n -= 100;
            } else if (n >= 50) {
                cout << "50 ";
                n -= 50;
            } else if (n >= 20) {
                cout << "20 ";
                n -= 20;
            } else if (n >= 10) {
                cout << "10 ";
                n -= 10;
            } else if (n >= 5) {
                cout << "5 ";
                n -= 5;
            } else if (n >= 2) {
                cout << "2 ";
                n -= 2;
            } else if (n >= 1) {
                cout << "1 ";
                n -= 1;
            }
        }
        cout << "\n";
    }
    return 0;
}