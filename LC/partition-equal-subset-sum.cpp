bool calc(vector<int>& nums, vector<unordered_map<int, bool>>& dp, int sum, int pos) {
    if (sum == 0) return true;
    if (sum < 0) return false;
    if (pos == nums.size()) return false;
    if (dp[pos].find(sum) != dp[pos].end()) return dp[pos][sum];
    if (calc(nums, dp, sum, pos + 1)) {
        dp[pos][sum] = true;
        return true;
    }
    if (calc(nums, dp, sum - nums[pos], pos + 1)) {
        dp[pos][sum] = true;
        return true;
    }
    dp[pos][sum] = false;
    return false;
}

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        sum /= 2;
        vector<unordered_map<int, bool>> dp(nums.size());
        return calc(nums, dp, sum, 0);
    }
};