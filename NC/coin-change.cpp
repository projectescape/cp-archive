class Solution
{
public:
    int findFewestCoinsRequired(int pos, vector<int> &coins, vector<int> &requiredCoins)
    {
        if (pos > requiredCoins.size())
        {
            return -1;
        }
        if (pos == requiredCoins.size())
        {
            return 0;
        }
        if (requiredCoins[pos] != -2)
        {
            return requiredCoins[pos];
        }

        int ans = INT_MAX;
        for (int coin : coins)
        {
            int moreCoinsRequired = findFewestCoinsRequired(pos + coin, coins, requiredCoins);
            if (moreCoinsRequired != -1)
            {
                ans = min(ans, 1 + moreCoinsRequired);
            }
        }

        if (ans != INT_MAX)
        {
            requiredCoins[pos] = ans;
        }
        else
        {
            requiredCoins[pos] = -1;
        }

        return requiredCoins[pos];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> requiredCoins(amount, -2);

        return findFewestCoinsRequired(0, coins, requiredCoins);
    }
};
