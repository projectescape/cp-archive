
class Solution
{
public:
    struct comp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;

        for (int i : nums)
        {
            m[i]++;
        }

        vector<int> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        for (auto i : m)
        {
            pq.push({i.first, i.second});
        }

        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
