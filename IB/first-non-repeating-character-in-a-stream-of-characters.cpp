string Solution::solve(string A) {
    unordered_map<char, int> m;
    queue<char> q;
    string ans;
    for (auto i : A) {
        m[i]++;
        if (m[i] == 1) q.push(i);
        while (!q.empty() && m[q.front()] != 1) q.pop();
        if (q.empty())
            ans += '#';
        else
            ans += q.front();
    }
    return ans;
}
