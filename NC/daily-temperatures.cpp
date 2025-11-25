class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temps)
    {
        if (temps.size() == 0)
        {
            return {};
        }

        stack<pair<int, int>> sp;

        vector<int> ans(temps.size(), 0);

        sp.push({temps[0], 0});

        for (int i = 1; i < temps.size(); i++)
        {
            int curr = temps[i];

            pair<int, int> top = sp.top();
            while (curr > top.first)
            {
                ans[top.second] = i - top.second;
                sp.pop();
                if (sp.empty())
                {
                    break;
                }
                top = sp.top();
            }
            sp.push({curr, i});
        }

        return ans;
    }
};
