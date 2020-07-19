int Solution::maxp3(vector<int> &A) {
    vector<int> pos;
    vector<int> neg;
    for (auto i : A) {
        if (i < 0) {
            neg.push_back(i);
        } else {
            pos.push_back(i);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int ans = INT_MIN;
    if (pos.size() > 2) {
        ans = max(ans, pos[pos.size() - 1] * pos[pos.size() - 2] * pos[pos.size() - 3]);
    }
    if (pos.size() > 1 && neg.size()) {
        ans = max(ans, neg[neg.size() - 1] * pos[pos.size() - 1] * pos[pos.size() - 2]);
    }
    if (neg.size() > 1 && pos.size()) {
        ans = max(ans, neg[0] * neg[1] * pos[pos.size() - 1]);
    }
    if (neg.size() > 2) {
        ans = max(ans, neg[neg.size() - 1] * neg[neg.size() - 2] * neg[neg.size() - 3]);
    }
    return ans;
}
