#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int n, int key) {
    int s = 0, e = n - 1;
    int mid;

    while (s <= e) {
        mid = (s + e) / 2;
        if (a[mid] == key) {
            return mid;
        }
        if (a[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {1, 3, 5, 10, 12, 15, 17};
    int n = sizeof(a) / sizeof(int);
    int key;

    cin >> key;

    int searchIndex = binarySearch(a, n, key);

    if (searchIndex == -1) {
        cout << "Key is not present\n";
    } else {
        cout << "Key is present at index " << searchIndex << endl;
    }

    return 0;
}