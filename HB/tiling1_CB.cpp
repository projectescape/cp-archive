//  Given a brick wall of 4XN, and tiles of size 4X1, find out the total no of ways to arrange tiles on the wall

#include <iostream>
using namespace std;

int tiling(int n) {
    if (n < 4) {
        return 1;
    }
    return tiling(n - 1) + tiling(n - 4);
}

int main() {
    int n;
    cin >> n;
    int ans = tiling(n);
    cout << ans << endl;
}