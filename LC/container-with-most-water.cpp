#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& h) {
        int ans = 0;

        for (int i = 0; i < h.size(); i++) {
            for (int j = h.size() - 1; j > i, (j - i) * h[i] > ans; j--) {
                if (h[j] >= h[i]) {
                    ans = (j - i) * h[i];
                    break;
                } else {
                    ans = max(ans, (j - i) * h[j]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << obj.maxArea(h) << endl;
}