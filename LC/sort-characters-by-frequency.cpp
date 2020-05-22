bool comp(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

class Solution {
   public:
    string frequencySort(string s) {
        vector<int> m(256, 0);
        for (auto &c : s) m[c]++;
        string ans = "";
        int i;
        vector<pair<char, int>> v;
        for (i = 0; i < 256; i++) {
            if (m[i])
                v.push_back({i, m[i]});
        }
        sort(v.begin(), v.end(), comp);
        for (auto c : v) {
            // cout<<c.first<<" "<<c.second<<endl;
            for (i = 0; i < c.second; i++) ans += c.first;
        }
        return ans;
    }
};