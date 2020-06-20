class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 0) return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] >= dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[index] < dp[i]) {
                index = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[index]);
        for (int i = index; i >= 0 && dp[index] > 1; i--) {
            if (dp[i] == dp[index] - 1 && nums[index] % nums[i] == 0) {
                ans.push_back(nums[i]);
                index = i;
            }
        }
        return ans;
    }
};