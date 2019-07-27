// https://www.interviewbit.com/problems/maxspprod/

// implementation 1 TLE, partial correct
int Solution::maxSpecialProduct(vector<int> &A) {
    // pair<int,int> P;
    int size = A.size();
    long long ans = 0;
    // for(int i=0;i<size();i++){
    //     P.push_back(make_pair(A[i],i));
    // }
    // sort(P.begin(),P.end());
    for (int i = 0; i < size; i++) {
        long long left = 0, right = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] > A[i]) {
                left = j;
                break;
            }
        }
        for (int j = i + 1; j < size; j++) {
            if (A[j] > A[i]) {
                right = j;
                break;
            }
        }
        if (((left * right) % 1000000007) > ans) {
            ans = (left * right) % 1000000007;
        }
    }
    return ans;
}

// Implementation 2, incorrect for large test cases

int Solution::maxSpecialProduct(vector<int> &A) {
    int size = A.size();
    long long ans = 0;
    vector<int> l = {0}, r = {0};
    l.reserve(size);
    r.reserve(size);
    stack<pair<int, int> > ls;
    for (int i = 0; i < size; i++) {
        long long x = 0;
        while (!ls.empty()) {
            if (ls.top().first > A[i]) {
                x = ls.top().second;
                break;
            } else {
                ls.pop();
            }
        }
        ls.push(make_pair(A[i], i));
        l[i] = x;
    }
    reverse(A.begin(), A.end());
    while (!ls.empty()) {
        ls.pop();
    }
    for (int i = 0; i < size; i++) {
        long long l = 0;
        while (!ls.empty()) {
            if (ls.top().first > A[i]) {
                l = ls.top().second;
                break;
            } else {
                ls.pop();
            }
        }
        ls.push(make_pair(A[i], size - 1 - i));
        r[size - 1 - i] = l;
    }
    for (int i = 0; i < size; i++) {
        if (l[i] * r[i] > ans) {
            ans = l[i] * r[i];
        }
    }
    return ans;
}
