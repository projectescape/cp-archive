class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0, j = s.length() - 1; i < j;)
        {
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
                  (s[i] >= '0' && s[i] <= '9')))
            {
                i++;
                continue;
            }
            if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') ||
                  (s[j] >= '0' && s[j] <= '9')))
            {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
