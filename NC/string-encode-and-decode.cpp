class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string ans;

        for (auto s : strs)
        {
            ans += (to_string(s.size()) + "#" + s);
        }

        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;

        for (int i = 0; i < s.size();)
        {
            int j = i;
            string length;
            while (s[j] != '#')
            {
                length += s[j];
                j++;
            }
            int lengthInt = stoi(length);
            string word = s.substr(j + 1, lengthInt);
            ans.push_back(word);
            i = j + 1 + stoi(length);
        }

        return ans;
    }
};
