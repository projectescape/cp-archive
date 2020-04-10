bool comp(vector<int> &a, vector<int> &b) {
    if (a[0] < b[0]) return true;
    if (b[0] < a[0]) return false;
    return a[1] < b[1];
}

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), comp);
        for (int i = 0; i < intervals.size();) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size()) {
                if (intervals[j][0] <= e) {
                    e = max(e, intervals[j][1]);
                    j++;
                } else {
                    break;
                }
            }
            ans.push_back({s, e});
            i = j;
        }
        return ans;
    }
};