class Solution {
   public:
    vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
            if (pq.size() == k + 1) pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        // sort(arr, arr + n, greater<int>());
        // vector<int> ans;
        // for (int i = 0; i < k; i++) ans.push_back(arr[i]);
        // return ans;
    }
};