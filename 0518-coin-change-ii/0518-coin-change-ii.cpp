class Solution {
public:
    int fun(int ind,int t,vector<int> &coins,vector<vector<int>> &dp){
        if(ind==0)return(t%coins[0]==0);
        if(dp[ind][t]!=-1)return dp[ind][t];

        int nottake=fun(ind-1,t,coins,dp);
        int take=0;
        if(coins[ind]<=t){
            take=fun(ind,t-coins[ind],coins,dp);
        }
        return dp[ind][t]= take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return
        fun(n-1,amount,coins,dp);
    }
};