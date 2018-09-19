class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        vector<int> row = maxInRow(grid);
        vector<int> col = maxInCol(grid);
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                res += min(row[i], col[j]) - grid[i][j];
        
        return res;
    }
    
    vector<int> maxInRow(vector<vector<int>>& grid) {
        vector<int> v;
        
        for (int i = 0; i < grid.size(); i++) {
            int mx = grid[i][0];
            for (int j = 0; j < grid[0].size(); j++)
                mx = max(mx, grid[i][j]);
            v.push_back(mx);
        }
        
        return v;
    }
    
    vector<int> maxInCol(vector<vector<int>>& grid) {
        vector<int> v;
        
        for (int j = 0; j < grid[0].size(); j++) {
            int mx = grid[0][j];
            for (int i = 0; i < grid.size(); i++)
                mx = max(mx, grid[i][j]);
            v.push_back(mx);
        }
        
        return v;
    }
    
};