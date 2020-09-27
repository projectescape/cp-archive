class Solution {
   public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        for (auto &i : m) {
            if (m.find(k - i.first) != m.end()) {
                if (k - i.first == i.first) {
                    ans += (i.second * (i.second - 1));
                } else {
                    ans += i.second * m[k - i.first];
                }
            }
        }
        return ans / 2;
    }
};