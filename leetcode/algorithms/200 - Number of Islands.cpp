class Solution {
    
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& used, int row, int col) {
        queue<vector<int>> q;
        q.push({row, col});
        used[row][col] = 1;
        
        const int rows = grid.size();
        const int cols = (grid.empty()) ? 0 : grid[0].size();
        
        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> v;
        int x, y;
        
        while (!q.empty()) {
            v = q.front();
            q.pop();
            
            for (int i = 0; i < d.size(); i++) {
                x = v[0] + d[i][0];
                y = v[1] + d[i][1];
                
                if (valid(x, y, rows, cols) && !used[x][y] && grid[x][y] == '1') {
                    q.push({x, y});
                    used[x][y] = 1;
                }
            }
        }
    }
    
    bool valid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        const int rows = grid.size();
        const int cols = (grid.empty()) ? 0 : grid[0].size();
        
        vector<vector<int>> used(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!used[i][j] && grid[i][j] == '1') {
                    bfs(grid, used, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
};