#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int x = 5;
void dfs(vector<int> graph[], int dp[][5], int u, int parent) {
    for (int i = 0; i < graph[u].size(); i++) {
        if (graph[u][i] != parent)
            dfs(graph, dp, graph[u][i], u);
    }
    for (int i = 1; i < x; i++) {
        dp[u][i] = i;
        for (int k = 0; k < graph[u].size(); k++) {
            int v = graph[u][k];
            if (v != parent) {
                int mini = 1e9;
                for (int j = 1; j < x; j++) {
                    if (j != i)
                        mini = min(mini, dp[v][j]);
                }
                dp[u][i] += mini;
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> graph[n + 1];
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        int dp[n + 1][5];
        memset(dp, 0, sizeof dp);
        dfs(graph, dp, 1, 0);
        cout << setw(15) << "Node" << setw(15) << "0" << setw(15) << "1" << setw(15) << "2"<< setw(15) << "3"<< setw(15) << "4" << endl;
        for (int i = 0; i < n + 1; i++) {
            cout<<setw(15)<<i;
            for (int j = 0; j < 5; j++) {
                cout << setw(15) << dp[i][j];
            }
            cout << endl<<endl;
        }
        int ans = dp[1][1];
        for (int i = 2; i < x; i++)
            ans = min(ans, dp[1][i]);
        cout << ans << endl;
    }

    return 0;
}