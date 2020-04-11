void getSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int>& v, int in = 0) {
    if (in == nums.size()) {
        ans.push_back(v);
        return;
    }
    getSubsets(nums, ans, v, in + 1);
    v.push_back(nums[in]);
    getSubsets(nums, ans, v, in + 1);
    v.pop_back();
    return;
}

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        if (nums.size() == 0) {
            ans.push_back(v);
            return ans;
        }
        getSubsets(nums, ans, v);
        return ans;
    }
};