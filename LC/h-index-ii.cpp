class Solution {
   public:
    int hIndex(vector<int>& c) {
        int s = 0, e = c.size() - 1, mid, size = c.size();
        int ans = 0;
        for (; s <= e;) {
            mid = s + (e - s) / 2;
            if (c[mid] >= size - mid) {
                ans = size - mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};