class Solution {
   public:
    bool checkTriplet(int arr[], int n) {
        sort(arr, arr + n);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0, k = i - 1; j < k;) {
                if (arr[i] * arr[i] == arr[j] * arr[j] + arr[k] * arr[k]) {
                    return true;
                } else if (arr[i] * arr[i] > arr[j] * arr[j] + arr[k] * arr[k]) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return false;
    }
};