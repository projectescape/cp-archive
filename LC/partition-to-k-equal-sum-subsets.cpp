bool helper(vector<int> &nums, vector<int> &v, int &sum, int pos) {
    if (pos == nums.size()) {
        for (auto &i : v) {
            if (i != sum) return false;
        }
        return true;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= sum) {
            v[i] += nums[pos];
            if (v[i] <= sum && helper(nums, v, sum, pos + 1)) return true;
            v[i] -= nums[pos];
            if (v[i] == 0) return false;
        }
    }
    return false;
}

class Solution {
   public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        sum /= k;
        vector<int> v(k, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return helper(nums, v, sum, 0);
    }
};