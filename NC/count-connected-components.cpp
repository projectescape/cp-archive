class Solution
{
public:
    void dfs(int curr, vector<bool> &visited, unordered_map<int, vector<int>> &edgeMap)
    {
        if (visited[curr])
        {
            return;
        }

        visited[curr] = true;

        for (int node : edgeMap[curr])
        {
            dfs(node, visited, edgeMap);
        }
    }

    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<bool> visited(n, false);

        unordered_map<int, vector<int>> edgeMap;

        for (auto &i : edges)
        {
            edgeMap[i[0]].push_back(i[1]);
            edgeMap[i[1]].push_back(i[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, visited, edgeMap);
            }
        }

        return ans;
    }
};
