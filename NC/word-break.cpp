class Solution
{
public:
    bool wordBreak(string &s, set<string> &wordDict, vector<int> &isValid, int pos)
    {
        if (pos == s.length())
        {
            return true;
        }
        if (isValid[pos] != -1)
        {
            return isValid[pos];
        }

        isValid[pos] = 0;
        string curr = "";

        for (int i = pos; i < s.length() && isValid[pos] != 1; i++)
        {
            curr += s[i];
            if (wordDict.find(curr) != wordDict.end())
            {
                if (wordBreak(s, wordDict, isValid, i + 1))
                {
                    isValid[pos] = 1;
                }
            }
        }

        return isValid[pos];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> isValid(s.length(), -1);
        set<string> wordDictSet;

        for (string word : wordDict)
        {
            wordDictSet.insert(word);
        }

        return wordBreak(s, wordDictSet, isValid, 0);
    }
};
