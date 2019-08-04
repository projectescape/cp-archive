#include <iostream>
using namespace std;

int convert(string data, int pos = -1) {
    if (pos == -1) {
        pos = data.size() - 1;
    }
    if (pos == 0) {
        return (data[0] - '0');
    }
    return (convert(data, pos - 1) * 10 + data[pos] - '0');
}

int main() {
    string data = "1234";
    cout << convert(data) << endl;
}