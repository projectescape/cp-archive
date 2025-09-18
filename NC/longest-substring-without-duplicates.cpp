class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charCount;

        int ans = 0;
        if (s.size() < 1)
        {
            return 0;
        }
        else
        {
            ans = 1;
            charCount[s[0]]++;
        }

        for (int i = 0, j = 1; j < s.length(); j++)
        {
            char currentChar = s[j];
            charCount[currentChar]++;
            while (charCount[currentChar] > 1)
            {
                charCount[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
