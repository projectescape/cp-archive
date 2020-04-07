int findIndex(vector<int>& nums, int target, int s, int e) {
    if (e < s || s > e) return -1;
    if (s == e) {
        if (nums[s] == target) return s;
        return -1;
    }
    int m = (s + e) / 2;
    if (nums[m] == target) return m;
    if (nums[m] > target) {
        if (nums[s] <= target || nums[s] > nums[m]) {
            return findIndex(nums, target, s, m - 1);
        } else {
            return findIndex(nums, target, m + 1, e);
        }
    }
    if (nums[e] >= target || nums[e] < nums[m]) {
        return findIndex(nums, target, m + 1, e);
    }
    return findIndex(nums, target, s, m - 1);
}

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        return findIndex(nums, target, 0, nums.size() - 1);
    }
};