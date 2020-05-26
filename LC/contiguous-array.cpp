class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = 0;
        int v;
        if (nums[0] == 1)
            v = 1;
        else
            v = -1;
        m[v] = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 1) {
                v += 1;
            } else
                v -= 1;
            if (m.find(v) == m.end()) {
                m[v] = i;
            } else {
                ans = max(i - m[v], ans);
            }
        }
        return ans;
    }
};