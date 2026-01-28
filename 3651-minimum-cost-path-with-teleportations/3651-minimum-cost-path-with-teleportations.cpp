

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int max_val = 0;
        for (const auto& row : grid) {
            for (int x : row) max_val = max(max_val, x);
        }
        
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        
        for (int t = 0; t <= k; ++t) {
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dist[r][c] == 1e9) continue;
                    
                    if (r + 1 < m) {
                        dist[r + 1][c] = min(dist[r + 1][c], dist[r][c] + grid[r + 1][c]);
                    }
                    if (c + 1 < n) {
                        dist[r][c + 1] = min(dist[r][c + 1], dist[r][c] + grid[r][c + 1]);
                    }
                }
            }
            
            if (t == k) break;
            
            vector<int> min_cost_by_val(max_val + 1, 1e9);
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dist[r][c] == 1e9) continue;
                    int val = grid[r][c];
                    min_cost_by_val[val] = min(min_cost_by_val[val], dist[r][c]);
                }
            }
            
            int current_min = 1e9;
            for (int v = max_val; v >= 0; --v) {
                current_min = min(current_min, min_cost_by_val[v]);
                min_cost_by_val[v] = current_min; 
            }
            
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    int val = grid[r][c];
                    if (min_cost_by_val[val] < dist[r][c]) {
                        dist[r][c] = min_cost_by_val[val];
                    }
                }
            }
        }
        
        return dist[m - 1][n - 1];
    }
};