class Solution {
public:
    int function(int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(m>=0&&(n>=0&&obstacleGrid[m][n]==1))return 0;
        if(m==0&&n==0)return 1;
        if(m<0||n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int left=0;int up=0;
       
        left=function(m-1,n,obstacleGrid,dp);
        
        up=function(m,n-1,obstacleGrid,dp);
        return dp[m][n]=left+up;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1)return 0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return function(m-1,n-1,obstacleGrid,dp);
    }
};