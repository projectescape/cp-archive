class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, vector<int>> m;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int currentNumber = nums[i];
            int requiredNumber = target - nums[i];
            if (currentNumber == requiredNumber)
            {
                if (m[currentNumber].size() > 1)
                {
                    return {m[currentNumber][0], m[currentNumber][1]};
                }
            }
            else
            {
                if (m[requiredNumber].size() > 0)
                {
                    return {m[currentNumber][0], m[requiredNumber][0]};
                }
            }
        }
        return {0, 0};
    }
};
