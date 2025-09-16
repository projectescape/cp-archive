class Solution
{
public:
    int findLowestNum(int num, unordered_map<int, bool> &m)
    {
        m[num] = true;

        if (m.find(num - 1) == m.end())
        {
            return num;
        }
        return findLowestNum(num - 1, m);
    }

    int findHighestNum(int num, unordered_map<int, bool> &m)
    {
        m[num] = true;

        if (m.find(num + 1) == m.end())
        {
            return num;
        }
        return findHighestNum(num + 1, m);
    }

    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> m;

        for (auto num : nums)
        {
            m[num] = false;
        }

        int ans = 0;

        for (auto num : nums)
        {
            if (m[num] == false)
            {
                int lowestNumber = findLowestNum(num, m);
                int highestNumber = findHighestNum(num, m);
                ans = max(ans, highestNumber - lowestNumber + 1);
            }
        }

        return ans;
    }
};
