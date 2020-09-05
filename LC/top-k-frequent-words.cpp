class comp {
   public:
    bool operator()(pair<string, int> &a, pair<string, int> &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

class Solution {
   public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> m;
        for (auto &i : words) m[i]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
        for (auto &i : m) pq.push(i);
        while (pq.size() != k) pq.pop();
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};