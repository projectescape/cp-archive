class Solution
{
public:
    int robAndRun(int pos, vector<int> &nums, vector<int> &amount, int start, int end)
    {
        if (pos > end)
        {
            return 0;
        }
        if (pos < start)
        {
            return 0;
        }
        if (amount[pos] != -1)
        {
            return amount[pos];
        }
        amount[pos] = max(nums[pos] + robAndRun(pos + 2, nums, amount, start, end),
                          robAndRun(pos + 1, nums, amount, start, end));

        return amount[pos];
    }

    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> amount(nums.size(), -1);

        int ans = robAndRun(0, nums, amount, 0, nums.size() - 2);

        amount = vector<int>(nums.size(), -1);

        return max(ans, robAndRun(1, nums, amount, 1, nums.size() - 1));
    }
};
