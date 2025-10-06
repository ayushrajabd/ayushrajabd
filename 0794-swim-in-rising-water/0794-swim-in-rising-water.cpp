class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> visited(n,vector<int>(n,0));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        pq.push({grid[0][0],0,0});
        vector<int> dirs={0,1,0,-1,0};
        int ans=0;
        while(!pq.empty()){
            auto[height,x,y]=pq.top();
            pq.pop();

            if(visited[x][y])continue;
            visited[x][y]=1;
            ans=max(ans,height);

            if(x==n-1&&y==n-1)return ans;

            for(int k=0;k<4;++k){
                int nx=x+dirs[k],ny=y+dirs[k+1];
                if(nx>=0&&ny>=0&&nx<n&&ny<n&&!visited[nx][ny]){
                    pq.push({grid[nx][ny],nx,ny});
                }
            }
        }return ans;
    }
};