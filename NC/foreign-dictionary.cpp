class Solution
{
public:
    bool dfs(char curr, stack<char> &s, unordered_map<char, bool> &visited, unordered_map<char, vector<char>> &edgeMap, set<char> &currSet)
    {
        if (visited[curr])
        {
            return true;
        }

        if (currSet.find(curr) != currSet.end())
        {
            return false;
        }

        currSet.insert(curr);

        for (char node : edgeMap[curr])
        {

            if (!dfs(node, s, visited, edgeMap, currSet))
            {
                return false;
            }
        }

        s.push(curr);
        visited[curr] = true;

        return true;
    }

    string foreignDictionary(vector<string> &words)
    {
        unordered_map<char, bool> visited;
        unordered_map<char, vector<char>> edgeMap;
        for (auto word : words)
        {
            for (char c : word)
            {
                visited[c] = false;
            }
        }
        for (int i = 1; i < words.size(); i++)
        {
            string word1 = words[i - 1];
            string word2 = words[i];

            cout << "Comparing " << word1 << ", " << word2 << endl;

            int j = 0;
            bool edgeAdded = false;
            for (; j < min(word1.size(), word2.size()); j++)
            {
                char char1 = word1[j], char2 = word2[j];

                cout << "Comparing " << char1 << ", " << char2 << endl;

                if (char1 != char2)
                {
                    edgeMap[char1].push_back(char2);
                    edgeAdded = true;
                    break;
                }
            }

            if (!edgeAdded && word1.length() > word2.length())
            {
                return "";
            }
        }

        stack<char> s;
        set<char> currSet;

        for (auto i : visited)
        {
            currSet = {};
            if (!dfs(i.first, s, visited, edgeMap, currSet))
            {
                return "";
            }
        }

        string ans;

        while (s.size() > 0)
        {
            ans += s.top();
            s.pop();
        }

        return ans;
    }
};
