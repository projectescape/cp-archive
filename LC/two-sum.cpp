#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());
        vector<int> a;
        for (int i = 0; i < v.size(); i++) {
            for (int j = v.size() - 1; j >= 0 && i != j; j--) {
                int sum = v[i].first + v[j].first;
                if (sum == target) {
                    a.push_back(v[i].second);
                    a.push_back(v[j].second);
                    return a;
                };
                if (sum < target) break;
            }
        }
        return a;
    }
};

int main() {
    vector<int> a = {3, 2, 4};
    int target = 6;
    Solution s;
    vector<int> ans = s.twoSum(a, target);

    cout << ans[0] << " " << ans[1] << endl;
}