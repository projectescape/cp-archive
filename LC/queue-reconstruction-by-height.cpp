bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> ans(people.size());
        int temp, j;
        for (auto i : people) {
            // cout<<"["<<i[0]<<","<<i[1]<<"], ";
            for (j = 0, temp = i[1]; temp > 0;) {
                if (ans[j].size() == 0 || ans[j][0] >= i[0]) {
                    temp--;
                }
                j++;
            }
            while (ans[j].size() != 0) j++;
            // cout<<"j :"<<j<<", ";
            ans[j] = i;
        }
        return ans;
    }
};