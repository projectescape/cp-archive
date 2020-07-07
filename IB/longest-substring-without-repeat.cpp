int Solution::lengthOfLongestSubstring(string A) {
    if (A.size() < 2) return A.size();
    unordered_map<char, int> m;
    int ans = 1;
    for (int i = 0, j = 0; i < A.size(); i++) {
        m[A[i]]++;
        while (m[A[i]] > 1) {
            m[A[j]]--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}
