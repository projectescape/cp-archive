bool compare(int a, int b) {
    return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
}

string Solution::largestNumber(const vector<int> &A) {
    int max = *max_element(A.begin(), A.end());
    int min = *min_element(A.begin(), A.end());
    if (max == min) {
        if (max == 0) {
            return "0";
        }
    }
    vector<int> B;
    for (int i = 0; i < A.size(); i++) {
        B.push_back(A[i]);
    }
    sort(B.begin(), B.end(), compare);
    string ans = "";

    for (int i = 0; i < A.size(); i++) {
        ans += to_string(B[i]);
    }
    return ans;
}
