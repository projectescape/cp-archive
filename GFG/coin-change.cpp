// https://practice.geeksforgeeks.org/problems/coin-change/0

#include <bits/stdc++.h>
using namespace std;

int ways(int m, int n, int arr[]) {
    int dp[n + 2];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) dp[i] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j + arr[i] <= n)
                dp[j + arr[i]] = dp[j + arr[i]] + dp[j];
            else
                break;
        }
    }
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        sort(arr, arr + m);
        cin >> n;
        cout << ways(m, n, arr) << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

// int helper(int amount,int pos, vector<vector<int>>&dp,vector<int>&coins){
//     if(pos>=coins.size()) return 0;
//     if(dp[amount][pos]==-1){
//         dp[amount][pos]=0;
//         int i;
//         for(i=amount;i>0;i-=coins[pos]){
//             dp[amount][pos]+=helper(i,pos+1,dp,coins);
//         }
//         if(i==0) dp[amount][pos]++;
//     }
//     return dp[amount][pos];
// }

// int main()
//  {
// 	int T,n,temp,amount;
// 	cin>>T;
// 	while(T--){
// 	    cin>>n;
// 	    vector<int> coins;
// 	    for(int i=0;i<n;i++){
// 	        cin>>temp;
// 	        coins.push_back(temp);
// 	    }
// 	    cin>>amount;
// 	    vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
// 	    cout<<helper(amount,0,dp,coins)<<endl;
// 	}
// 	return 0;
// }