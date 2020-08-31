vector<vector<int>> Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    long long curr;
    for (long long i = 0, j, k; i < A.size();) {
        for (j = i + 1, k = A.size() - 1; j < k;) {
            curr = A[i];
            curr += A[j];
            curr += A[k];
            if (curr > 0) {
                while (j < k && A[k - 1] == A[k]) k--;
                k--;
            } else if (curr < 0) {
                while (j < k && A[j + 1] == A[j]) j++;
                j++;
            } else {
                ans.push_back({A[i], A[j], A[k]});
                while (j < k && A[j + 1] == A[j]) j++;
                while (j < k && A[k - 1] == A[k]) k--;
                j++;
                k--;
            }
        }
        while (i < A.size() - 1 && A[i + 1] == A[i]) i++;
        i++;
    }
    return ans;
}
