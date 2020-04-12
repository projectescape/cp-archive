class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
        cout << endl;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == 0) {
                if (nums[i + 1] == 0 && nums[i + 2] == 0) {
                    ans.push_back({0, 0, 0});

                    while (i < nums.size() && nums[i] == 0) {
                        i++;
                    }
                    i--;
                    continue;
                }
            }
            if (nums[i + 1] == nums[i + 2] && nums[i] == nums[i + 1]) {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    cout << i << " " << j << " " << k << endl;
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                } else {
                    k--;
                }
            }
            if (nums[i + 1] == nums[i]) {
                i++;
            }
        }
        return ans;
    }
};