class Solution {
   public:
    string getPermutation(int k, int n) {
        n--;
        vector<long long> fact(10, 1);
        for (int i = 2; i < 10; i++) {
            fact[i] = i * fact[i - 1];
        }
        vector<bool> v(10, false);
        v[0] = true;
        string ans = "";
        int in, j;
        for (int i = 0; i < k; i++) {
            in = n / (fact[k - 1 - i]);
            // cout<<"n :"<<n<<", in :"<<in<<endl;
            for (j = 1; in >= 0; j++) {
                if (!v[j]) {
                    in--;
                    if (in == -1) {
                        v[j] = true;
                        ans += '0' + j;
                    }
                }
            }
            n = n % fact[k - 1 - i];
        }

        return ans;
    }
};