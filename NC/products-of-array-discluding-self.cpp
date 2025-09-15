class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int countOfZeros = 0;
        int productOfAll = 1;

        for (auto num : nums)
        {
            if (num == 0)
            {
                countOfZeros++;
            }
            else
            {
                productOfAll *= num;
            }
        }

        vector<int> ans;

        for (auto num : nums)
        {
            if (countOfZeros > 1)
            {
                ans.push_back(0);
            }

            else if (num == 0)
            {
                ans.push_back(productOfAll);
            }
            else if (countOfZeros == 1)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(productOfAll / num);
            }
        }

        return ans;
    }
};
