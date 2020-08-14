bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    for (int i = 0, j = 0; i < arrive.size() && K >= 0; i++) {
        K--;
        for (; j < depart.size() && depart[j] <= arrive[i]; j++, K++)
            ;
    }
    return K >= 0;
}
