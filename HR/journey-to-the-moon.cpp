void helper(int &curr, vector<vector<int>> &g, vector<bool> &visited, int &temp) {
    for (auto i : g[curr]) {
        if (!visited[i]) {
            visited[i] = true;
            temp++;
            helper(i, g, visited, temp);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> num;
    vector<bool> visited(n, false);
    vector<vector<int>> g(n);
    int temp = 0;
    for (auto i : astronaut) {
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp = 1;
            helper(i, g, visited, temp);
            num.push_back(temp);
        }
    }
    int ans = 0;
    for (int i = 0; i < num.size(); i++) {
        for (int j = i + 1; j < num.size(); j++) {
            ans += (num[i] * num[j]);
        }
    }
    return ans;
}