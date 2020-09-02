bool comp(int &a, int &b) { return a < b; }

vector<int> Solution::solve(vector<int> &A) {
    if (A.size() == 0) return {};
    for (int i = 0; i < A.size(); i++) {
        A[i] *= A[i];
    }
    sort(A.begin(), A.end(), comp);
    return A;
}
