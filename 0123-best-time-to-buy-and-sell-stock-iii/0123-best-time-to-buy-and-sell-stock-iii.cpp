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
       vector<vector<int>> dp(n,vector<int> (5,-1));
       return fun(0,4,prices,n,dp);
    }
};