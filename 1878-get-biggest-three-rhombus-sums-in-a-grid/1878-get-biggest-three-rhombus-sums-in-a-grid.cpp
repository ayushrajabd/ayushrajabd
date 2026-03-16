class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> s;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                s.insert(grid[i][j]);
                
                for(int k = 1; ; k++){
                    if(i-k < 0 || i+k >= m || j-k < 0 || j+k >= n) break;
                    
                    int sum = 0;
                    
                    for(int t = 0; t < k; t++) sum += grid[i-k+t][j+t];
                    for(int t = 0; t < k; t++) sum += grid[i+t][j+k-t];
                    for(int t = 0; t < k; t++) sum += grid[i+k-t][j-t];
                    for(int t = 0; t < k; t++) sum += grid[i-t][j-k+t];
                    
                    s.insert(sum);
                }
            }
        }

        vector<int> res;
        for(auto x : s){
            res.push_back(x);
            if(res.size() == 3) break;
        }
        return res;
    }
};