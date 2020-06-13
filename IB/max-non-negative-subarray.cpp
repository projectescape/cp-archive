vector<int> Solution::maxset(vector<int> &A) {
    vector<pair<int, long long>> sum(A.size(), {-1, -1});
    vector<int> ans;
    if (A.size() == 0) {
        return ans;
    }
    if (A[0] >= 0) sum[0] = {0, A[0]};
    for (long long i = 1; i < A.size(); i++) {
        if (A[i] >= 0) {
            if (A[i - 1] >= 0) {
                sum[i] = {sum[i - 1].first, sum[i - 1].second + A[i]};
            } else {
                sum[i] = {i, A[i]};
            }
        } else {
            sum[i] = {-1, -1};
        }
    }
    long long max = -1, index = -1;
    for (long long i = 0; i < A.size(); i++) {
        if (sum[i].first > -1) {
            if (sum[i].second > max) {
                max = sum[i].second;
                index = i;
                continue;
            } else if (sum[i].second == max) {
                if ((i - sum[i].first) > (index - sum[index].first)) {
                    index = i;
                }
            }
        }
    }
    if (index > -1) {
        for (int i = sum[index].first; i <= index; i++) {
            ans.push_back(A[i]);
        }
    }
    return ans;
}
