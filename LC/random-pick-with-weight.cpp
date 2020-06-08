class Solution {
   public:
    vector<int> v;
    Solution(vector<int>& w) {
        v = w;
        for (int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }
    }

    int pickIndex() {
        return upper_bound(v.begin(), v.end(), rand() % v[v.size() - 1]) - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */