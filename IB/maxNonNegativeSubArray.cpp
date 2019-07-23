// https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int>& A) {
    vector<int> ans, temp;
    long long prevSum = 0, sum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] >= 0) {
            temp.push_back(A[i]);
            sum += (long long)A[i];
        } else {
            if (sum > prevSum) {
                prevSum = sum;
                sum = 0;
                ans = temp;
            } else if (sum == prevSum) {
                if (temp.size() > ans.size()) {
                    ans = temp;
                    sum = 0;
                }
            }
            temp.clear();
            sum = 0;
        }
    }
    if (sum > prevSum) {
        prevSum = sum;
        sum = 0;
        ans = temp;
        temp.clear();
    } else if (sum == prevSum) {
        if (temp.size() > ans.size()) {
            ans = temp;
            sum = 0;
            temp.clear();
        }
    }
    return ans;
}