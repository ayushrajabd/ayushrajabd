class Solution {
public:
    int fun(int index,int t,vector<int>& coins,vector<vector<int>> &dp){
        if(index==0){
            if(t%coins[0]==0)return t/coins[0];
            else return 1e9; 

        }
        if(dp[index][t]!=-1)return dp[index][t];
        int nottake=fun(index-1,t,coins,dp);
        int take=1e9;
        if(coins[index]<=t){
            take=1+fun(index,t-coins[index],coins,dp);

        }
        return dp[index][t]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= fun(n-1,amount,coins,dp);
        if(ans==1e9)return -1;
         return ans;


        




    }
};