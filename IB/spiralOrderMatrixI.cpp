// https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    long long m1 = -1, m2 = A.size();
    long long n1 = -1, n2 = A[0].size();
    vector<int> ans;
    long long i = 0, j = 0;
    ans.push_back(A[j][i]);
    while (m2 - m1 > 1 && n2 - n1 > 1) {
        for (i++; i < n2; i++) {
            ans.push_back(A[j][i]);
        }
        i--;
        m1++;
        for (j++; j < m2; j++) {
            ans.push_back(A[j][i]);
        }
        j--;
        n2--;
        if (m2 - m1 > 1) {
            for (i--; i > n1; i--) {
                ans.push_back(A[j][i]);
            }
            i++;
            m2--;
        }
        if (n2 - n1 > 1) {
            for (j--; j > m1; j--) {
                ans.push_back(A[j][i]);
            }
            j++;
            n1++;
        }
    }
    return ans;
}