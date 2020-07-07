int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int, int> m;
    int count = 0;
    for (auto i : A) {
        m[i]++;
    }
    for (auto i : m) {
        if (i.second > 0) {
            m[i.first]--;
            if (i.first >= B) {
                if (m.find(i.first - B) != m.end() && m[i.first - B] > 0) {
                    return 1;
                }
            } else {
                if (m.find(i.first + B) != m.end() && m[i.first + B] > 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
