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
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    profit=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};