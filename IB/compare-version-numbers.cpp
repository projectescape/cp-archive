//  Dont waste your time on this question, faaltu ke test cases
int Solution::compareVersion(string A, string B) {
    vector<string> a, b;
    string temp = "";
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != '.') {
            temp += A[i];
        }
        if (A[i] == '.' || i == A.size() - 1) {
            a.push_back(temp);
            temp = "";
        }
    }
    temp = "";
    for (int i = 0; i < B.size(); i++) {
        if (B[i] != '.') {
            temp += B[i];
        }
        if (B[i] == '.' || i == B.size() - 1) {
            b.push_back(temp);
            temp = "";
        }
    }
    long long j, k;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) {
            if (i < b.size()) {
                // cout<<A<<endl<<a[i]<<endl<<B<<endl<<b[i]<<endl;
                j = stoll(a[i]);
                k = stoll(b[i]);
                if (j < k)
                    return -1;
                else if (j > k)
                    return 1;
                else
                    continue;
            } else {
                return 1;
            }
        } else if (i < b.size())
            return -1;
    }
    return 0;
}
