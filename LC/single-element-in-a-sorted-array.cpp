class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int i, j, m;
        for (i = 0, j = nums.size() - 1;;) {
            if (i == j) return nums[i];
            m = i + (j - i) / 2;
            if (nums[m] == nums[m - 1]) {
                if ((m - i) & 1) {
                    i = m + 1;
                } else {
                    j = m - 2;
                }
                continue;
            } else if (nums[m] == nums[m + 1]) {
                if ((j - m) & 1) {
                    j = m - 1;
                } else {
                    i = m + 2;
                }
                continue;
            } else {
                return nums[m];
            }
        }
        return 0;
    }
};