class Solution {
   public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> pre(A.size(), -1);
        vector<int> post(A.size() + 1, -1);
        int i = 0;
        int ans = 0;
        for (; i < L; i++) {
            ans += A[i];
        }
        pre[i - 1] = ans;
        for (; i < A.size(); i++) {
            ans -= A[i - L];
            ans += A[i];
            pre[i] = max(pre[i - 1], ans);
        }
        ans = 0;
        for (i = A.size() - 1; i > A.size() - 1 - L; i--) {
            ans += A[i];
        }
        post[i + 1] = ans;
        for (; i >= 0; i--) {
            ans -= A[i + L];
            ans += A[i];
            post[i] = max(post[i + 1], ans);
        }
        int curr = 0;
        for (i = 0; i < M; i++) {
            curr += A[i];
        }
        cout << curr << " ";
        ans = max(ans, curr + post[i]);
        for (; i < A.size(); i++) {
            curr -= A[i - M];
            curr += A[i];
            if (i - M >= 0)
                ans = max(ans, curr + pre[i - M]);
            ans = max(ans, curr + post[i + 1]);
        }
        return ans;
    }
};