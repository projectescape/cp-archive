class Solution
{
public:
    int findMaxSeq(int pos1, int pos2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (pos1 >= text1.length() || pos2 >= text2.length())
        {
            return 0;
        }
        if (dp[pos1][pos2] != -1)
        {
            return dp[pos1][pos2];
        }
        int ans = 0;

        if (text1[pos1] == text2[pos2])
        {
            ans = 1 + findMaxSeq(pos1 + 1, pos2 + 1, text1, text2, dp);
        }

        dp[pos1][pos2] = max({ans, findMaxSeq(pos1 + 1, pos2, text1, text2, dp), findMaxSeq(pos1, pos2 + 1, text1, text2, dp)});

        return dp[pos1][pos2];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));

        cout << dp.size() << endl
             << dp[0].size() << endl;

        return findMaxSeq(0, 0, text1, text2, dp);
    }
};
