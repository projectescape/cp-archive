class Solution
{
public:
    void flow(vector<vector<int>> &heights, vector<vector<bool>> &currFlow, int i, int j)
    {

        if (i + 1 < heights.size() && heights[i + 1][j] >= heights[i][j] && !currFlow[i + 1][j])
        {
            currFlow[i + 1][j] = true;
            flow(heights, currFlow, i + 1, j);
        }

        if (j + 1 < heights[0].size() && heights[i][j + 1] >= heights[i][j] && !currFlow[i][j + 1])
        {
            currFlow[i][j + 1] = true;
            flow(heights, currFlow, i, j + 1);
        }

        if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j] && !currFlow[i - 1][j])
        {
            currFlow[i - 1][j] = true;
            flow(heights, currFlow, i - 1, j);
        }

        if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j] && !currFlow[i][j - 1])
        {
            currFlow[i][j - 1] = true;
            flow(heights, currFlow, i, j - 1);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        for (int j = 0; j < heights[0].size(); j++)
        {
            pacific[0][j] = true;
            atlantic[heights.size() - 1][j] = true;
        }

        for (int i = 0; i < heights.size(); i++)
        {
            pacific[i][0] = true;
            atlantic[i][heights[0].size() - 1] = true;
        }

        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
                if (pacific[i][j])
                {
                    flow(heights, pacific, i, j);
                }
                if (atlantic[i][j])
                {
                    flow(heights, atlantic, i, j);
                }
            }
        }

        vector<vector<int>> ans;

        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[0].size(); j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
