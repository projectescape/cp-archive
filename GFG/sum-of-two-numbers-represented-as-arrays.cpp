class Solution {
   public:
    vector<int> findSum(vector<int> &a, vector<int> &b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.size() < b.size()) swap(a, b);
        int c = 0;
        for (int i = 0; i < b.size(); i++) {
            a[i] += (b[i] + c);
            c = a[i] / 10;
            a[i] = a[i] % 10;
        }
        if (c) {
            for (int i = b.size(); i < a.size(); i++) {
                a[i] += c;
                c = a[i] / 10;
                a[i] = a[i] % 10;
            }
        }
        if (c) a.push_back(1);
        reverse(a.begin(), a.end());
        return a;
    }
};