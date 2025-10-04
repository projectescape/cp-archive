class Solution
{
public:
    void populateAnsRecursively(vector<int> &nums,
                                vector<int> curr,
                                vector<vector<int>> &ans,
                                int target,
                                int index, int currentSum)
    {

        if (target == currentSum)
        {
            ans.push_back(curr);
            return;
        }

        if (index == nums.size())
        {
            return;
        }

        do
        {
            populateAnsRecursively(nums, curr, ans, target, index + 1, currentSum);

            currentSum += nums[index];
            curr.push_back(nums[index]);

        } while (!(currentSum > target));
    }

    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        populateAnsRecursively(nums, curr, ans, target, 0, 0);

        return ans;
    }
};
