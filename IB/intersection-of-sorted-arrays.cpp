vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    for (long long i = 0, j = 0; i < A.size() && j < B.size();) {
        if (A[i] == B[j]) {
            ans.push_back(A[i]);
            i++, j++;
            continue;
        }
        if (A[i] < B[j]) {
            i++;
            continue;
        }
        if (A[i] > B[j]) {
            j++;
            continue;
        }
    }
    return ans;
}
