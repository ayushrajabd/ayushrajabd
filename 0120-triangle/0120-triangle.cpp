class Solution {
public:
    int function(int n,int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp){
       
        if(i==n-1)return triangle[n-1][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int down=triangle[i][j]+function(n,i+1,j,triangle,dp);
        int diag=triangle[i][j]+function(n,i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,diag);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp
        (n);
        for(int i=0;i<n;i++){
            dp[i]=vector<int>(i+1,-1);
        }
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=triangle[i][j]+dp[i+1][j];
                int dg=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,dg);
            }
        }
        return dp[0][0];
    }
};