int Solution::bulbs(vector<int> &A) {
    int want = 1;
    int ans = 0;
    for (auto i : A) {
        if (i != want) {
            ans++;
            if (want)
                want = 0;
            else
                want = 1;
        }
    }
    return ans;
}
