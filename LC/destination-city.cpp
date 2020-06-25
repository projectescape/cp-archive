class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> m;
        for (auto i : paths) {
            m[i[0]] = true;
            if (!m[i[1]]) {
                m[i[1]] = false;
            }
        }
        for (auto i : m) {
            if (!i.second) {
                return i.first;
            }
        }
        return "Hello";
    }
};