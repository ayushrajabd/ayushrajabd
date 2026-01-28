class Solution {
public:
    int fun(int index,int buy,vector<int>& prices,int n,vector<vector<int>> &dp){
        int profit=0;
        if(index==n)return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        if(buy){
         profit= max(-prices[index]+fun(index+1,0,prices,n,dp),fun(index+1,1,prices,n,dp));
        }
        else{
         profit= max(prices[index]+fun(index+1,1,prices,n,dp),fun(index+1,0,prices,n,dp));

        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return fun(0,1,prices,n,dp);
    }
};