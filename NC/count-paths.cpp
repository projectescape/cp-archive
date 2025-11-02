class Solution
{
public:
    int findPaths(vector<vector<int>> &paths, int i, int j, int m, int n)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }

        if (paths[i][j] != -1)
        {
            return paths[i][j];
        }

        paths[i][j] = findPaths(paths, i, j + 1, m, n) + findPaths(paths, i + 1, j, m, n);

        return paths[i][j];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> paths(m, vector<int>(n, -1));

        paths[m - 1][n - 1] = 1;

        return findPaths(paths, 0, 0, m, n);
    }
};
