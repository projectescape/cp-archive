void bfs(vector<int> A[], int i, int j, int &N, int &M) {
    if (i >= N || i < 0 || j < 0 || j >= M || A[i][j] != 1) {
        return;
    }
    A[i][j] = 2;
    bfs(A, i - 1, j, N, M);
    bfs(A, i - 1, j + 1, N, M);
    bfs(A, i - 1, j - 1, N, M);
    bfs(A, i, j - 1, N, M);
    bfs(A, i, j + 1, N, M);
    bfs(A, i + 1, j, N, M);
    bfs(A, i + 1, j - 1, N, M);
    bfs(A, i + 1, j + 1, N, M);
}

int findIslands(vector<int> A[], int N, int M) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 1) {
                count++;
                bfs(A, i, j, N, M);
            }
        }
    }
    return count;
}