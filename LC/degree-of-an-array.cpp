class Solution {
   public:
    int findShortestSubArray(vector<int>& nums) {
        int d = 0;
        unordered_map<int, int> m, n;
        for (auto& i : nums) {
            m[i]++;
            d = max(d, m[i]);
        }
        int ans = nums.size();
        for (int i = 0, j = 0; j < nums.size(); j++) {
            n[nums[j]]++;
            if (n[nums[j]] == d) {
                for (; nums[i] != nums[j]; i++) {
                    n[nums[i]]--;
                }
                ans = min(ans, j - i + 1);
                if (ans == d) return ans;
            }
        }
        return ans;
    }
};