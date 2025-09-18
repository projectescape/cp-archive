class Solution
{
public:
    char getNewMaxNum(unordered_map<char, int> &charCount)
    {
        char ans = charCount.begin()->first;

        for (auto i : charCount)
        {
            if (i.second > charCount[ans])
            {
                ans = i.first;
            }
        }
        return ans;
    }

    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> charCount;
        if (s.length() < 1)
        {
            return 0;
        }
        int ans = 1;
        charCount[s[0]] = 1;
        char maxNum = s[0];

        for (int left = 0, right = 1; right < s.length(); right++)
        {
            charCount[s[right]]++;
            while (right - left + 1 > charCount[maxNum] + k)
            {
                charCount[s[left]]--;

                left++;
                maxNum = getNewMaxNum(charCount);
            }
            cout << "left is " << left << ", right is " << right << endl;
            ans = max(ans, right - left + 1);
            maxNum = getNewMaxNum(charCount);
        }

        return ans;
    }
};
