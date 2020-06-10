class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i;
        vector<int> ans;
        for (i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};