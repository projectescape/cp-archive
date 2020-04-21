class Solution {
   public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int i = -1, j = -1, k = 0;
        for (; k < nums.size(); k++) {
            if (v[k] != nums[k]) {
                i = j = k;
                break;
            }
        }
        for (k++; k < nums.size(); k++) {
            if (v[k] != nums[k]) j = k;
        }
        if (i != -1) return j - i + 1;
        return 0;
    }
};