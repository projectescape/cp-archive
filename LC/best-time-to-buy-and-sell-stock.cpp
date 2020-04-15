class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int l = prices[0];
        int i = 0, ans = 0;
        for (; i < prices.size(); i++) {
            ans = max(prices[i] - l, ans);
            l = min(l, prices[i]);
        }
        return ans;
    }
};