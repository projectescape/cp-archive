class Solution {
   public:
    bool hasArrayTwoCandidates(int arr[], int n, int x) {
        sort(arr, arr + n);
        for (int i = 0, j = n - 1; i < j;) {
            if (arr[i] + arr[j] == x) return true;
            if (arr[i] + arr[j] < x)
                i++;
            else
                j--;
        }
        return false;
    }
};