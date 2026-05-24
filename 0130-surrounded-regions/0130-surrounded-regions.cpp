class Solution {
public:

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> out(n,vector<char>(m,'X'));
        queue <pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1||j==m-1||i==0||j==0){
                    if(vis[i][j]==0&&board[i][j]=='O'){
                    q.push({i,j});
                    out[i][j]='O';
                    vis[i][j]=1;}

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
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&board[nr][nc]=='O'){
                    vis[nr][nc]=1;
                    out[nr][nc]='O';
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=out[i][j];
            }
        }
        
    }
};