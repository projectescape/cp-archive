class Solution {
   public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(N + 1);
        for (auto i : dislikes) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<char> visited(N + 1, 'n');
        visited[1] = 'a';
        queue<int> q;
        int temp;
        for (int i = 1; i <= N; i++) {
            q.push(i);
            while (!q.empty()) {
                temp = q.front();
                q.pop();
                if (visited[temp] == 'a') {
                    for (auto i : adj[temp]) {
                        if (visited[i] == 'a') return false;
                        if (visited[i] == 'b') continue;
                        visited[i] = 'b';
                        q.push(i);
                    }
                } else {
                    for (auto i : adj[temp]) {
                        if (visited[i] == 'b') return false;
                        if (visited[i] == 'a') continue;
                        visited[i] = 'a';
                        q.push(i);
                    }
                }
            }
        }

        return true;
    }
};