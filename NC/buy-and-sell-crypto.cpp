class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;

        for (int i = 0, j = 1; j < prices.size();)
        {
            int diff = prices[j] - prices[i];
            if (diff < 0)
            {
                i = j;
                j = j + 1;
            }
            else if (diff > ans)
            {
                ans = diff;
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};
