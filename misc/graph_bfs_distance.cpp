
void bfs(T src) {
    queue<T> q;
    map<T, int> dist;
    map<T, T> parent;

    for (auto i : adjList) {
        dist[i.first] = INT_MAX;
    }

    q.push(src);
    parent[src] = src;

    while (!q.empty()) {
        T node = q.front();
        cout << node << " ";
        q.pop();
        for (T neighbour : adjList[node]) {
            if (dist[neighbour] == INT_MAX) {
                q.push(neighbour);
                dist[neighbour] = dist[node] + 1;
                parent[neighbour] = node;
            }
        }
    }
    for (auto i : adjList) {
        T node = i.first;
        cout << "Distance of " << node << " from " << src << " = " << dist[node] << endl;
    }
}
}
