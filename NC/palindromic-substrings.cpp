class Solution
{
public:
    int countSubstrings(string s)
    {
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int begin = i, end = i;
            for (; begin - 1 >= 0 && end + 1 < s.size();)
            {
                if (s[begin - 1] != s[end + 1])
                {
                    break;
                }
                begin--;
                end++;
            }
            ans += (end - begin + 2) / 2;
            if (i + 1 < s.size() && s[i] == s[i + 1])
            {
                int begin = i, end = i + 1;
                for (; begin - 1 >= 0 && end + 1 < s.size();)
                {
                    if (s[begin - 1] != s[end + 1])
                    {
                        break;
                    }
                    begin--;
                    end++;
                }
                ans += (end - begin + 1) / 2;
            }
        }
        return ans;
    }
};
