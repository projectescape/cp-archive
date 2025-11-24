class Solution
{
public:
    bool areMapEqual(unordered_map<char, int> &m1, unordered_map<char, int> &m2)
    {
        if (m1.size() != m2.size())
        {
            return false;
        }

        for (auto i : m1)
        {
            if (m2[i.first] != i.second)
            {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
        {
            return false;
        }
        unordered_map<char, int> m1, m2;
        for (auto c : s1)
        {
            m1[c]++;
        }

        for (int i = 0; i < s1.length() - 1; i++)
        {
            m2[s2[i]]++;
        }

        for (int i = s1.length() - 1; i < s2.length(); i++)
        {
            m2[s2[i]]++;
            if (areMapEqual(m1, m2))
            {
                return true;
            }
            m2[s2[i + 1 - s1.length()]]--;
            if (m2[s2[i + 1 - s1.length()]] == 0)
            {
                m2.erase(s2[i + 1 - s1.length()]);
            }
        }

        return false;
    }
};
