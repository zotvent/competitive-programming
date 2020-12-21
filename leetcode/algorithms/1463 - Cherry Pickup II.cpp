class Solution {
    
    int dp(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& mem) {
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size()) {
            return 0;
        }
        
        if (mem[row][col1][col2] != -1) {
            return mem[row][col1][col2];
        }
        
        int res = grid[row][col1];
        if (col1 != col2) res += grid[row][col2];
        
        if (row != grid.size() - 1) {
            int mx = 0;
            
            for (int c1 = col1 - 1; c1 <= col1 + 1; c1++) {
                for (int c2 = col2 - 1; c2 <= col2 + 1; c2++) {
                    mx = max(mx, dp(row + 1, c1, c2, grid, mem));
                }
            }
            
            res += mx;
        }
        
        return mem[row][col1][col2] = res;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> mem(rows);
        
        for (int i = 0; i < rows; i++) {
            mem[i].resize(cols);
            for (int j = 0; j < cols; j++) {
                mem[i][j].resize(cols);
                for (int k = 0; k < cols; k++) {
                    mem[i][j][k] = -1;
                }
            }
        }
        
        return dp(0, 0, cols - 1, grid, mem);
    }
};