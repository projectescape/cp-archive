class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> m;

        for (auto i : nums)
        {
            if (m.find(i) == m.end())
            {
                m[i] = true;
            }
            else
            {

                return true;
            }
        }
        return false;
    }
};