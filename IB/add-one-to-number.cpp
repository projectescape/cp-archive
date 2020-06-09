vector<int> Solution::plusOne(vector<int> &A) {
    if (A.size() == 0) {
        A.push_back(1);
        return A;
    }
    int carry = 1, i;
    for (i = A.size() - 1; i >= 0 && carry == 1; i--) {
        A[i]++;
        if (A[i] > 9) {
            A[i] = A[i] % 10;
        } else {
            carry = 0;
        }
    }
    vector<int> ans;
    if (carry == 1) {
        ans.push_back(1);
        for (i = 0; i < A.size(); i++) {
            ans.push_back(A[i]);
        }
    } else {
        for (i = 0; A[i] == 0; i++)
            ;
        for (; i < A.size(); i++) {
            ans.push_back(A[i]);
        }
    }
    return ans;
}
