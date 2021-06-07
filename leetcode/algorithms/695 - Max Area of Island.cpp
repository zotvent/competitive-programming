class Solution {
    
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& used, int row, int col) {
        int res = 0, r, c;
        const int rows = grid.size();
        const int cols = grid[0].size();
        queue<vector<int>> q;
        vector<int> cur;
        const vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        q.push({row, col});
        used[row][col] = 1;
        
        while (!q.empty()) {
            res++;
            cur = q.front();
            q.pop();
            
            for (int i = 0; i < d.size(); i++) {
                r = cur[0] + d[i][0];
                c = cur[1] + d[i][1];
                
                if (valid(r, c, rows, cols) && !used[r][c] && grid[r][c] == 1) {
                    used[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
        
        return res;
    }
    
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, area;
        const int rows = grid.size();
        const int cols = grid[0].size();
        vector<vector<int>> used(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!used[i][j] && grid[i][j] == 1) {
                    area = bfs(grid, used, i, j);
                    res = max(res, area);
                }
            }
        }
        
        return res;
    }
};