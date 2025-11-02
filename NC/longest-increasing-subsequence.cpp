class Solution
{
public:
    int lengthOfLIS(vector<int> &nums, vector<int> &length, int pos)
    {
        if (pos >= nums.size())
        {
            return 0;
        }
        if (length[pos] != -1)
        {
            return length[pos];
        }
        length[pos] = 1;

        for (int i = pos + 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[pos])
            {
                length[pos] = max(length[pos], 1 + lengthOfLIS(nums, length, i));
            }
        }
        return length[pos];
    }

    int lengthOfLIS(vector<int> &nums)
    {

        vector<int> length(nums.size(), -1);

        for (int i = 0; i < nums.size(); i++)
        {
            if (length[i] == -1)
            {
                lengthOfLIS(nums, length, i);
            }
        }

        int ans = 0;
        for (auto i : length)
        {
            ans = max(ans, i);
        }
        return ans;
    }
};
