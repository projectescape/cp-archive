void makePermute(vector<int>& nums, vector<vector<int>>& ans, int index = 0) {
    if (index == nums.size()) {
        ans.push_back(nums);
    }
    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        makePermute(nums, ans, index + 1);
        swap(nums[i], nums[index]);
    }
}

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        makePermute(nums, ans);
        return ans;
    }
};