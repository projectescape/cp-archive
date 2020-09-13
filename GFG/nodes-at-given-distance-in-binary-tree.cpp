class solver {
   private:
   public:
    void bfs(Node*& root, vector<int>& ans, int k) {
        if (!root) return;
        if (k == 0) {
            ans.push_back(root->data);
            return;
        }
        bfs(root->left, ans, k - 1);
        bfs(root->right, ans, k - 1);
    }

    int helper(Node*& root, int& target, int& k, vector<int>& ans) {
        if (!root) return INT_MAX;
        if (root->data == target) {
            bfs(root, ans, k);
            return k - 1;
        }
        int dist = helper(root->left, target, k, ans);
        if (dist == 0) {
            ans.push_back(root->data);
            return INT_MAX;
        }
        if (dist != INT_MAX) {
            bfs(root->right, ans, dist - 1);
            return dist - 1;
        }
        dist = helper(root->right, target, k, ans);
        if (dist == 0) {
            ans.push_back(root->data);
            return INT_MAX;
        }
        if (dist != INT_MAX) {
            bfs(root->left, ans, dist - 1);
            return dist - 1;
        }
        return INT_MAX;
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        vector<int> ans;
        helper(root, target, k, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};