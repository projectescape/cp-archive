#include <iostream>
#include <string>

using namespace std;

int permute(char *a, int i) {
    if (a[i] == '\0') {
        cout << a << ", ";
        return 0;
    }
    for (int j = i; a[j] != '\0'; j++) {
        swap(a[j], a[i]);
        permute(a, i + 1);
        swap(a[j], a[i]);
    }
}

int main() {
    char a[100] = "abc";
    permute(a, 0);
}
