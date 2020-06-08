class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ans(people.size(), vector<int>(2, -1));
        int count, i;
        for (auto p : people) {
            count = p[1];
            for (i = 0;;) {
                if (count == 0) {
                    if (ans[i][0] == -1) {
                        ans[i] = p;
                        break;
                    } else {
                        i++;
                        continue;
                    }
                } else {
                    if (ans[i][0] == -1) {
                        count--;
                        i++;

                    } else if (ans[i][0] >= p[0]) {
                        count--;
                        i++;
                    } else {
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};