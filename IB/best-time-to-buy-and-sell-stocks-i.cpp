int Solution::maxProfit(const vector<int> &A) {
    int profit = 0, buy = 0;
    for (int i = 1; i < A.size(); i++) {
        profit = max(profit, A[i] - A[buy]);
        if (A[buy] > A[i]) {
            buy = i;
        }
    }
    return profit;
}
