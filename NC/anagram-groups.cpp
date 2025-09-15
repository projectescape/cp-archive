class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mapToStringList;

        for (string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mapToStringList[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto pair : mapToStringList)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
