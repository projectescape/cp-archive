class Solution
{
public:
    struct comp
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[0] < b[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        if (intervals.size() == 0)
        {
            return {};
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> prev = ans[ans.size() - 1];
            vector<int> curr = intervals[i];

            if (curr[0] <= prev[1])
            {
                ans[ans.size() - 1][1] = max(curr[1], prev[1]);
            }
            else
            {
                ans.push_back(curr);
            }
        }

        return ans;
    }
};
