bool comp(string &a, unordered_map<string, int> m, int in, int size) {
    string temp;
    for (int i = in; i < in + size; i++) {
        temp += a[i];
        if (m.find(temp) != m.end() && m[temp] > 0) {
            m[temp]--;
            temp = "";
        }
    }
    if (temp == "")
        return true;
    else
        return false;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;
    if (A.size() == 0) return ans;
    unordered_map<string, int> m;
    long long size = 0, hash = 0;
    for (auto i : B) {
        m[i]++;
        size += i.size();
        for (auto c : i) hash += (c - 'a');
    }
    if (A.size() < size) return ans;
    long long temp = 0;
    for (int i = 0; i < size; i++) {
        temp += (A[i] - 'a');
    }
    if (temp == hash && comp(A, m, 0, size)) ans.push_back(0);
    for (int i = 1; i + size <= A.size(); i++) {
        temp -= A[i - 1];
        temp += A[i + size - 1];
        if (temp == hash && comp(A, m, i, size)) ans.push_back(i);
    }
    return ans;
}
