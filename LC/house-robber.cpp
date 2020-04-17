int calcAns(vector<int>& nums, vector<int>& dp, int index) {
    if (index >= nums.size()) return 0;
    if (dp[index] != -1) return dp[index];
    dp[index] = max(nums[index] + calcAns(nums, dp, index + 2), calcAns(nums, dp, index + 1));
    return dp[index];
}

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), -1);
        return calcAns(nums, dp, 0);
    }
};