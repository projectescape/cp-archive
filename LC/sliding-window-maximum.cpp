class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), temp;
        vector<int> ans;
        deque<pair<int, int>> dq;
        for (int i = 0; i < k; i++) {
            temp = nums[i];
            if (dq.empty() || dq.front().first <= temp) {
                dq.push_front({temp, i});
            } else {
                while (!dq.empty() && dq.back().first <= temp) dq.pop_back();
                dq.push_back({temp, i});
            }
        }
        ans.push_back(dq.front().first);
        for (int i = k; i < n; i++) {
            temp = nums[i];
            if (dq.front().first <= temp) {
                dq.push_front({temp, i});
            } else {
                while (!dq.empty() && (dq.back().first <= temp || dq.back().second <= i - k)) dq.pop_back();
                dq.push_back({temp, i});
            }
            while (dq.front().second <= i - k) dq.pop_front();
            ans.push_back(dq.front().first);
        }
        return ans;
    }
};