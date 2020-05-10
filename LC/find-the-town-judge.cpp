class Solution {
   public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustMe(N + 1, 0);
        vector<int> trustOthers(N + 1, 0);
        for (int i = 0; i < trust.size(); i++) {
            trustOthers[trust[i][0]]++;
            trustMe[trust[i][1]]++;
        }
        for (int i = 1; i < trustMe.size(); i++) {
            if (trustMe[i] == N - 1) {
                if (trustOthers[i] == 0) return i;
            }
        }
        return -1;
    }
};