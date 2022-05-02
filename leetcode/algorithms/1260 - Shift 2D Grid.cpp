class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res = grid;
        const int n = grid.size();
        const int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int index = (i * m + j + k) % (n * m);
                res[index / m][index % m] = grid[i][j];
            }
        }
        
        return res;
    }
};