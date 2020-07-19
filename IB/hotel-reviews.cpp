bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    unordered_map<string, bool> m;
    string temp;
    for (auto i : A) {
        if (i == '_') {
            m[temp] = true;
            temp = "";
        } else
            temp += i;
    }
    if (temp != "") m[temp] = true;
    vector<pair<int, int>> v;
    pair<int, int> p;
    for (int i = 0; i < B.size(); i++) {
        temp = "";
        p = {0, i};
        for (auto c : B[i]) {
            if (c == '_') {
                if (m[temp]) {
                    p.first++;
                }
                temp = "";
            } else
                temp += c;
        }
        if (temp != "") {
            if (m[temp]) {
                p.first++;
            }
        }
        v.push_back(p);
    }
    sort(v.begin(), v.end(), comp);
    vector<int> ans;
    for (auto i : v) {
        ans.push_back(i.second);
    }
    return ans;
}
