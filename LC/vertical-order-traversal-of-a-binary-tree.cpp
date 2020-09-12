bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    if (a.second.first == b.second.first) return a.first < b.first;
    return a.second.first < b.second.first;
}

class Solution {
    int x = 0;

   public:
    void dfs(TreeNode *&curr, map<int, vector<pair<int, pair<int, int>>>> &m, int pos, int h) {
        if (!curr) return;
        m[pos].push_back({curr->val, {h, x}});
        x++;
        dfs(curr->left, m, pos - 1, h + 1);
        dfs(curr->right, m, pos + 1, h + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root) {
        map<int, vector<pair<int, pair<int, int>>>> m;
        dfs(root, m, 0, 0);
        vector<vector<int>> ans;
        for (auto &i : m) {
            // for(auto &j:i.second){
            sort(i.second.begin(), i.second.end(), comp);
            ans.push_back({});
            for (auto &n : i.second) {
                ans[ans.size() - 1].push_back(n.first);
            }
            // }
        }
        return ans;
    }
};