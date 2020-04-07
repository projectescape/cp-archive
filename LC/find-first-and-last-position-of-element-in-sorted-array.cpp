class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto h = upper_bound(nums.begin(), nums.end(), target);
        if (l == nums.end() || *l != target) {
            ans.push_back(-1);
            ans.push_back(-1);
        } else {
            ans.push_back(l - nums.begin());
            ans.push_back(h - nums.begin() - 1);
        }
        return ans;
    }
};
