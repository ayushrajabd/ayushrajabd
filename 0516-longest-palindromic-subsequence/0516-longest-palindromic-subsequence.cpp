class Solution {
public:
    int fun(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(i==0||j==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1]){
            return dp[i][j]=1+fun(i-1,j-1,s,t,dp);
        }
        else{
            return dp[i][j]=max(fun(i-1,j,s,t,dp),fun(i,j-1,s,t,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string t=s;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        reverse(t.begin(),t.end());
        return fun(n,n,s,t,dp);

    }
};