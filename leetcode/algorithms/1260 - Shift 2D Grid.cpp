class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res = grid;
        
        int n = grid.size();
        int m = grid[0].size();
        int index;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                index = (i * m + j + k) % (n * m);
                res[index / m][index % m] = grid[i][j];
            }
        }
        
        return res;
    }
};