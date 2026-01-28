class Solution {
public:
    int fun(int index,int tran,vector<int> &prices,int n,vector<vector<int>>&dp){
        if(index==n||tran==0)return 0;
        if(dp[index][tran]!=-1)return dp[index][tran];
        if(tran%2==0){
            return dp[index][tran]=max(-prices[index]+fun(index+1,tran-1,prices,n,dp),fun(index+1,tran,prices,n,dp));
        }
        else{
            return dp[index][tran]=max(prices[index]+fun(index+1,tran-1,prices,n,dp),fun(index+1,tran,prices,n,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size(); 
       vector<vector<int>> dp(n+1,vector<int> (5,0));
       for(int i=n-1;i>=0;i--){
        for(int j=1;j<=4;j++){
            if(j%2==0)
            dp[i][j]=max(-prices[i]+dp[i+1][j-1],dp[i+1][j]);
            else{
                dp[i][j]=max(prices[i]+dp[i+1][j-1],dp[i+1][j]);
            }
        }
       }
       return dp[0][4];
       
    }
};