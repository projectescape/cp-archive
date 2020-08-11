int Solution::maxArr(vector<int> &A) {
    int pos, neg;
    pos = neg = A[0];
    int ans = 0;
    for (int i = 1; i < A.size(); i++) {
        ans = max({ans, A[i] - pos + i, neg - A[i] + i});
        pos = min(pos, A[i] + i);
        neg = max(neg, A[i] - i);
    }
    return ans;
}