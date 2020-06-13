int Solution::firstMissingPositive(vector<int> &A) {
    int i;
    for (i = 0; i < A.size(); i++) {
        if (A[i] > A.size() || A[i] <= 0) {
            A[i] = A.size() + 1;
        }
    }
    for (i = 0; i < A.size(); i++) {
        if (abs(A[i]) <= A.size()) {
            A[abs(A[i]) - 1] = -1 * abs(A[abs(A[i]) - 1]);
        }
    }
    for (i = 0; i < A.size(); i++) {
        if (A[i] > 0) return i + 1;
    }
    return A.size() + 1;
}

// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int firstMissingPositive(vector<int> &A) {
//     long long size = A.size(), negIndex = A.size() - 1;
//     // Initialize new array with all values 1
//     for (long long i = 0; i < size; i++) {
//         if (A[i] < size + 1 && A[i] > 0) {
//             long long temp = 0, j = i;
//             while (1) {
//                 cout << "temp " << temp << " i " << i << " j " << j << endl;
//                 temp = A[A[i] - 1];
//                 A[A[i] - 1] = size;
//                 if (temp - 1 == i) {
//                     break;
//                 }
//                 if (A[temp] <= size) {
//                     i = temp;
//                 } else {
//                     break;
//                 }
//             }
//             i = j;
//         }
//     }
//     for (long long i = 0; i < size; i++) {
//         if (A[i] != size) {
//             return i;
//         }
//     }
// }
// int main() {
//     vector<int> A = {1, 3, -1, 4};
//     cout << firstMissingPositive(A) << endl;
// }