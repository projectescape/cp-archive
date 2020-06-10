int Solution::maxSpecialProduct(vector<int> &A) {
    stack<pair<int, long long>> s;
    s.push({INT_MAX, 0});
    vector<long long> prod(A.size(), 1);
    long long ans = 0;
    for (long long i = 0; i < A.size(); i++) {
        while (s.top().first <= A[i]) {
            s.pop();
        }
        prod[i] = (prod[i] * (s.top().second));
        s.push({A[i], i});
    }
    stack<pair<int, long long>> p;
    p.push({INT_MAX, 0});
    for (long long i = A.size() - 1; i >= 0; i--) {
        while (p.top().first <= A[i]) {
            p.pop();
        }
        prod[i] = (prod[i] * (p.top().second));
        p.push({A[i], i});
        ans = max(ans, prod[i]);
    }
    return ans % 1000000007;
}
