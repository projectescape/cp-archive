bool comp(vector<int>& a, vector<int>& b) {
    return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
}

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), comp);
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};