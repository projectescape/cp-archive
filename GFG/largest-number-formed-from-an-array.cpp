bool comp(string &a, string &b) {
    return b + a < a + b;
}
class Solution {
   public:
    string printLargest(vector<string> &arr) {
        sort(arr.begin(), arr.end(), comp);
        string ans;
        for (auto &i : arr) ans += i;
        return ans;
    }
};