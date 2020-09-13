int maxLen(int arr[], int N) {
    int ans = 0;
    unordered_map<int, int> m;
    m[0] = -1;
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1) {
            c++;
        } else {
            c--;
        }
        if (m.find(c) == m.end()) {
            m[c] = i;
        } else {
            ans = max(ans, i - m[c]);
        }
    }

    return ans;
}