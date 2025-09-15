class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> m1, m2;

        for (char c : s)
        {
            m1[c]++;
        }
        for (char c : t)
        {
            m2[c]++;
        }

        if (m1.size() != m2.size())
        {
            return false;
        }

        for (auto i : m1)
        {
            if (i.second != m2[i.first])
            {
                return false;
            }
        }
        return true;
    }
};
