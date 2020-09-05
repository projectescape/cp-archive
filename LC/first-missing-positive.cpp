class Solution {
   public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.size() == 0) return 1;
        for (auto &i : nums) {
            if (i <= 0) i = nums.size() + 1;
        }
        for (auto &i : nums) {
            if (abs(i) <= nums.size()) {
                if (nums[abs(i) - 1] > 0) {
                    nums[abs(i) - 1] *= -1;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return i + 1;
        }
        return nums.size() + 1;
    }
};