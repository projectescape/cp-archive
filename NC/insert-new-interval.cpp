class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newI)
    {

        if (intervals.size() == 0)
        {
            return {newI};
        }

        vector<vector<int>> temp;

        if (newI[0] <= intervals[0][0])
        {
            temp.push_back(newI);
            for (auto i : intervals)
            {
                temp.push_back(i);
            }
        }
        else
        {
            temp.push_back(intervals[0]);
            bool inserted = false;
            for (int i = 1; i < intervals.size(); i++)
            {
                if (inserted)
                {
                    temp.push_back(intervals[i]);
                    continue;
                }
                if (newI[0] <= intervals[i][0])
                {
                    temp.push_back(newI);
                    temp.push_back(intervals[i]);
                    inserted = true;
                }
                else
                {
                    temp.push_back(intervals[i]);
                }
            }
            if (!inserted)
            {
                temp.push_back(newI);
            }
        }

        vector<vector<int>> ans;

        ans.push_back(temp[0]);

        for (int i = 1; i < temp.size(); i++)
        {
            vector<int> prev = ans[ans.size() - 1];
            vector<int> curr = temp[i];

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
