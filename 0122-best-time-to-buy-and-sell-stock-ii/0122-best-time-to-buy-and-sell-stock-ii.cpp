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
        vector<int> ahead(2,0),curr(2,0);
        int aheadnotbuy,aheadbuy,currnotbuy,currbuy;
        aheadnotbuy=aheadbuy=currnotbuy=currbuy=0;
        for(int ind=n-1;ind>=0;ind--){
            currbuy=max(-prices[ind]+aheadnotbuy,aheadbuy);
            currnotbuy=max(prices[ind]+aheadbuy,aheadnotbuy);
            aheadnotbuy=currnotbuy;
            aheadbuy=currbuy;
        }
        return aheadbuy;
    }
};