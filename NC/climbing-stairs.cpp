class Solution
{
public:
    int findNumberOfWays(int pos, vector<int> &numberOfWays)
    {
        if (pos > numberOfWays.size())
        {
            return 0;
        }
        if (pos == numberOfWays.size())
        {
            return 1;
        }
        if (numberOfWays[pos] != 0)
        {
            return numberOfWays[pos];
        }
        numberOfWays[pos] = findNumberOfWays(pos + 1, numberOfWays) + findNumberOfWays(pos + 2, numberOfWays);
        return numberOfWays[pos];
    }

    int climbStairs(int n)
    {
        vector<int> numberOfWays(n, 0);

        return findNumberOfWays(0, numberOfWays);
    }
};
