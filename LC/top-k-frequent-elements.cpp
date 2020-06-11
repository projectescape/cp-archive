bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i : nums) m[i]++;
        vector<pair<int, int>> p;
        for (auto i : m) {
            p.push_back(i);
        }
        sort(p.begin(), p.end(), comp);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(p[i].first);
        }
        return ans;
    }
};