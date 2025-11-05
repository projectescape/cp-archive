class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = *max_element(nums.begin(), nums.end());
        ;
        int currSum = 0;

        for (int i : nums)
        {
            if (currSum < 0)
            {
                currSum = 0;
            }
            currSum += i;
            ans = max(ans, currSum);
        }

        return ans;
    }
};
