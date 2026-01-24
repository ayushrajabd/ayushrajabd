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
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }

        for(int i=1;i<=n-1;i++){
            for(int j=0;j<=amount;j++){
                int nottake=0+dp[i-1][j];
                int take=1e9;
                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];

                }
                dp[i][j]=min(take,nottake);
            }
        }
        if(dp[n-1][amount]==1e9){
            return -1;

        }
        return dp[n-1][amount];

        




    }
};