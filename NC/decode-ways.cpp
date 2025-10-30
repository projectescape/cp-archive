class Solution
{
public:
    int findDecodings(int pos, string &s, vector<int> &ans)
    {

        if (pos >= s.length())
        {
            return 1;
        }
        if (ans[pos] != -1)
        {
            return ans[pos];
        }

        string currString = string() + s[pos];

        if (stoi(currString) == 0)
        {
            ans[pos] = 0;
            return ans[pos];
        }

        ans[pos] = findDecodings(pos + 1, s, ans);

        if (pos + 1 < s.length())
        {
            currString += s[pos + 1];
            if (stoi(currString) <= 26)
            {
                ans[pos] += findDecodings(pos + 2, s, ans);
            }
        }

        return ans[pos];
    }

    int numDecodings(string s)
    {
        vector<int> ans(s.size(), -1);

        return findDecodings(0, s, ans);
    }
};
