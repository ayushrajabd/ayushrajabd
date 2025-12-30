class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        
        if (grid[r + 1][c + 1] != 5) return false;

        
        vector<bool> seen(10, false);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen[val])
                    return false;
                seen[val] = true;
            }
        }

        
        int s = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        
        for (int i = 0; i < 3; i++) {
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != s)
                return false;
        }

        
        for (int j = 0; j < 3; j++) {
            if (grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != s)
                return false;
        }

        
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != s)
            return false;

        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != s)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        if (row < 3 || col < 3) return 0;

        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
