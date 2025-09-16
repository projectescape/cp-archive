class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int curr = 0; curr < nums.size(); curr++)
        {
            if (curr > 0 && nums[curr - 1] == nums[curr])
            {
                continue;
            }
            int target = nums[curr];

            int i = curr + 1, j = nums.size() - 1;

            while (i < j)
            {
                int leftNum = nums[i];
                int rightNum = nums[j];
                int ansLength = ans.size();
                if (target + leftNum + rightNum == 0)
                {

                    if (ansLength == 0 ||
                        !(target == ans[ansLength - 1][0] && leftNum == ans[ansLength - 1][1] && rightNum == ans[ansLength - 1][2]))
                    {
                        ans.push_back({target, leftNum, rightNum});
                    }
                    i++;
                    continue;
                }
                else if (target + leftNum + rightNum < 0)
                {
                    i++;
                    continue;
                }
                else
                {
                    j--;
                }
            }
        }

        return ans;
    }
};

// [-1,0,1,2,-1,-4]
// [-4,-1,-1,0,1,2]