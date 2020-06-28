int Solution::lengthOfLastWord(const string A) {
    int ans = 0;
    bool space = false;
    for (auto i : A) {
        if (i == ' ') {
            space = true;
            continue;
        }
        if (space) {
            ans = 1;
            space = false;
        } else
            ans++;
    }
    return ans;
}
