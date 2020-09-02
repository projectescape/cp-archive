vector<int> Solution::maxone(vector<int> &A, int B) {
    int s = 0, e = 0;
    int max = 0;
    for (int i = 0, j = 0; j < A.size(); j++) {
        if (A[j] == 0) {
            B--;
            if (B < 0) {
                while (A[i] == 1) i++;
                i++;
                B++;
            }
        }
        if (j - i > max) {
            max = j - i;
            s = i;
            e = j;
        }
    }
    vector<int> ans;
    for (int i = s; i <= e; i++) {
        ans.push_back(i);
    }
    return ans;
}
