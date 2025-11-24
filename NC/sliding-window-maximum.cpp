class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        set<int, greater<int>> s;
        unordered_map<int, int> m;

        for (int i = 0; i < k - 1; i++)
        {
            s.insert(nums[i]);
            m[nums[i]]++;
        }

        vector<int> ans;
        for (int i = k - 1; i < nums.size(); i++)
        {
            s.insert(nums[i]);
            m[nums[i]]++;

            ans.push_back(*(s.begin()));

            m[nums[i + 1 - k]]--;
            if (m[nums[i + 1 - k]] == 0)
            {
                s.erase(nums[i + 1 - k]);
            }
        }

        return ans;
    }
};
