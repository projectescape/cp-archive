bool findTriplets(int arr[], int n) {
    // sort(arr, arr + n);
    // int sum;
    // unordered for (int i = 0, j, k; i < n - 2; i++) {
    //     for (j = i + 1; j < n - 1; j++) {
    //         sum = arr[i] + arr[j];
    //         sum *= -1;
    //         if (binary_search(arr + j + 1, arr + n, sum)) return true;
    //     }
    // }
    // unordered_map<int, int> m;
    // for (int i = 0; i < n; i++) {
    //     m[arr[i]]++;
    // }
    // for (int i = 0; i < n - 2; i++) {
    //     m[arr[i]]--;
    //     for (int j = i + 1; j < n - 1; j++) {
    //         m[arr[j]]--;
    //         if (m[(arr[i] + arr[j]) * -1]) return true;
    //         m[arr[j]]++;
    //     }
    //     m[arr[i]]--;
    // }
    sort(arr, arr + n);
    for (int j = i + 1, k = n - 1; j < k;) {
        if (arr[i] + arr[j] + arr[k] == 0)
            return true;
        else if (arr[i] + arr[j] + arr[k] < 0)
            j++;
        else
            k--;
    }
}
return false;
}