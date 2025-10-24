class Solution
{
public:
    bool dfs(int currNode, int parentNode, unordered_map<int, vector<int>> &edgeMap, set<int> &visited, unordered_map<int, bool> &covered)
    {
        if (visited.find(currNode) != visited.end())
        {
            // Loop detected
            return false;
        }
        visited.insert(currNode);
        covered[currNode] = true;
        for (auto node : edgeMap[currNode])
        {
            if (node == parentNode)
            {
                continue;
            }
            if (!dfs(node, currNode, edgeMap, visited, covered))
            {
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> edgeMap;
        unordered_map<int, bool> covered;
        for (int i = 0; i < n; i++)
        {
            covered[i] = false;
            edgeMap[i] = {};
        }
        for (auto &i : edges)
        {
            edgeMap[i[0]].push_back(i[1]);
            edgeMap[i[1]].push_back(i[0]);
        }

        set<int> visited;
        if (!dfs(0, -1, edgeMap, visited, covered))
        {
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            if (!covered[i])
            {
                return false;
            }
        }

        return true;
    }
};
