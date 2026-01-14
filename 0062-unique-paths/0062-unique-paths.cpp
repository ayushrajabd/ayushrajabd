class Solution {
public:
    int function(int i,int j,vector<vector<int>> &dp){
        
        if(i==0||j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=function(i-1,j,dp);
        int left=function(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,(vector<int> (n,-1)));
        return function(m-1,n-1,dp);
    }
};