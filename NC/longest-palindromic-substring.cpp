class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans = "";

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
            if (ans.size() < end - begin + 1)
            {
                ans = s.substr(begin, end - begin + 1);
            }
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
                if (ans.size() < end - begin + 1)
                {
                    ans = s.substr(begin, end - begin + 1);
                }
            }
        }
        return ans;
    }
};
