package NC.java;

public class BuyAndSellCrypto {
    public int maxProfit(int[] prices) {

        if (prices.length == 0) {
            return 0;
        }

        int minPrice = prices[0];
        int ans = 0;

        for (int i = 1; i < prices.length; i++) {
            int curr = prices[i];

            ans = Math.max(ans, curr - minPrice);

            minPrice = Math.min(minPrice, curr);

        }
        return ans;
    }
}
