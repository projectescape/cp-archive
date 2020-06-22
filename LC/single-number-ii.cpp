class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        vector<int> d(32, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                d[j] += (nums[i] & 1);
                nums[i] = nums[i] >> 1;
                if (!nums[i]) break;
            }
        }
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            ans = ans << 1;
            ans += d[i] % 3;
        }
        return ans;
    }
};