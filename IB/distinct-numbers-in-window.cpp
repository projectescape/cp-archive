vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int, int> m;
    int count = 0;
    vector<int> ans;
    int i = 0;
    for (; i < B; i++) {
        if (m[A[i]] == 0) {
            count++;
        }
        m[A[i]]++;
    }
    ans.push_back(count);
    for (; i < A.size(); i++) {
        if (A[i - B] == A[i]) {
            ans.push_back(count);
            continue;
        }
        if (m[A[i - B]] == 1) {
            count--;
        }
        if (m[A[i]] == 0) {
            count++;
        }
        m[A[i]]++;
        m[A[i - B]]--;
        ans.push_back(count);
    }
    return ans;
}