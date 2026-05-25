


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||i==n-1||j==0||j==m-1){
                    if(grid[i][j]==1&&vis[i][j]==0){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int drow=row+dr[i];
                int dcol=col+dc[i];
                if(drow>=0&&drow<n&&dcol>=0&&dcol<m&&vis[drow][dcol]==0&&grid[drow][dcol]==1){
                q.push({drow,dcol});
                vis[drow][dcol]=1;

                }
            }

        }
        int inone=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    count++;
                }

            }
        }
        return count;


    }
};