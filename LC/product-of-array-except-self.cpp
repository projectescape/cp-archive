class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 1) return nums;
        vector<int> ans(nums.size(), 1);
        ans[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            ans[i] = nums[i] * ans[i + 1];
        }
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i - 1];
        }
        ans[0] = ans[1];
        for (int i = 1; i < nums.size() - 1; i++) {
            ans[i] = nums[i - 1] * ans[i + 1];
        }
        ans[nums.size() - 1] = nums[nums.size() - 2];
        return ans;
    }
};