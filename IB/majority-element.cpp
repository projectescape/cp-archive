int Solution::majorityElement(const vector<int> &A) {
    int count = 1;
    int ans = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (A[i] == ans) {
            count++;
        } else {
            count--;
            if (count == 0) {
                ans = A[i];
                count = 1;
            }
        }
    }
    return ans;
}
