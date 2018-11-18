class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        int size = grid.size();
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j])
                    res += 2;
            }
        }
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {                
                if (!i) res += grid[i][j];
                else res += abs(grid[i][j] - grid[i - 1][j]);
                if (i == size - 1) res += grid[i][j];
                
                if (!j) res += grid[i][j];
                else res += abs(grid[i][j] - grid[i][j - 1]);
                if (j == size - 1) res += grid[i][j];
            }
        }
        
        return res;
    }
};