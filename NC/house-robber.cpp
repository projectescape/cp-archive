class Solution
{
public:
    int robAndRun(int pos, vector<int> &nums, vector<int> &amount)
    {
        if (pos >= nums.size())
        {
            return 0;
        }
        if (amount[pos] != -1)
        {
            return amount[pos];
        }
        amount[pos] = max(nums[pos] + robAndRun(pos + 2, nums, amount), robAndRun(pos + 1, nums, amount));

        return amount[pos];
    }

    int rob(vector<int> &nums)
    {
        vector<int> amount(nums.size(), -1);

        return robAndRun(0, nums, amount);
    }
};
