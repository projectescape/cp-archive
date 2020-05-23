class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int s, e;
        for (int i = 0, j = 0; i < A.size() && j < B.size();) {
            s = max(A[i][0], B[j][0]);
            e = min(A[i][1], B[j][1]);
            if (s <= e) ans.push_back({s, e});
            if (A[i][1] < B[j][1])
                ++i;
            else
                ++j;
        }
        return ans;
    }
};