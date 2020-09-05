void helper(vector<int>& nums, vector<vector<int>>& s, int pos) {
    if (pos == nums.size()) {
        s.push_back(nums);
        return;
    }
    helper(nums, s, pos + 1);
    unordered_map<int, bool> m;
    m[nums[pos]] = true;
    for (int i = pos + 1; i < nums.size(); i++) {
        if (m[nums[i]]) continue;
        m[nums[i]] = true;
        swap(nums[i], nums[pos]);

        helper(nums, s, pos + 1);
        swap(nums[i], nums[pos]);
    }
}

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> s;
        sort(nums.begin(), nums.end());
        helper(nums, s, 0);
        vector<vector<int>> ans;
        // for(auto &i:s) ans.push_back(i);
        // return ans;
        return s;
    }
};