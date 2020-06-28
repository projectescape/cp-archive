bool checkIn(char &c, vector<int> &v) {
    for (auto i : v) {
        if (i == c) return true;
    }
    return false;
}

int Solution::solve(string A) {
    long long ans = 0;
    vector<int> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < A.size(); i++) {
        if (checkIn(A[i], v)) {
            ans += (A.size() - i);
        }
    }

    return ans % 10003;
}
