vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> p = A;

    sort(p.begin(), p.end());
    int a = -1, b = -1;
    for (int i = 0; i < A.size(); i++) {
        if (p[i] != A[i]) {
            a = i;
            break;
        }
    }
    if (a == -1) return {-1};
    for (int i = a + 1; i < A.size(); i++) {
        if (p[i] != A[i]) {
            b = i;
        }
    }
    return {a, b};
}
