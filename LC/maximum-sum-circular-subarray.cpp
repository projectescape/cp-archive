class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        vector<int> B = A;
        int maxSub = A[0], minSub = B[0];
        for (int i = 1; i < A.size(); i++) {
            A[i] = max(A[i], A[i] + A[i - 1]);
            maxSub = max(maxSub, A[i]);
            B[i] = min(B[i], B[i] + B[i - 1]);
            minSub = min(minSub, B[i]);
        }
        if (sum == minSub && maxSub < 0) {
            return maxSub;
        }
        if (sum - minSub > maxSub) {
            return sum - minSub;
        }
        return maxSub;
    }
};