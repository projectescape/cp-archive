void getSol(vector<int>& candidates, int& target, vector<int>& v, vector<vector<int>>& ans, int current = 0, int index = 0) {
    int temp;
    for (int i = index; i < candidates.size(); i++) {
        temp = current + candidates[i];
        if (temp >= target) {
            if (temp == target) {
                v.push_back(candidates[i]);
                ans.push_back(v);
                v.pop_back();
            }
            break;
        }
        v.push_back(candidates[i]);
        getSol(candidates, target, v, ans, temp, i);
        v.pop_back();
    }
}

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        getSol(candidates, target, v, ans);
        return ans;
    }
};