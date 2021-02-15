class Solution {
    
    vector<pair<int, int>> bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col) {
        vector<pair<int, int>> res;
        queue<vector<int>> q;
        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> cur;
        int x, y;
        const int rows = grid.size();
        const int cols = (grid.empty() ? 0 : grid[0].size());
        
        q.push({row, col});
        visited[row][col] = 1;
        res.push_back({0, 0});
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            
            for (int i = 0; i < d.size(); i++) {
                x = cur[0] + d[i][0];
                y = cur[1] + d[i][1];
                
                if (valid(x, y, rows, cols) && grid[x][y] && !visited[x][y]) {
                    q.push({x, y});
                    visited[x][y] = 1;
                    res.push_back({x - row, y - col});
                }
            }
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
    
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> unique;
        vector<pair<int, int>> cur;
        const int rows = grid.size();
        const int cols = (grid.empty() ? 0 : grid[0].size());
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    cur = bfs(grid, visited, i, j);
                    unique.insert(cur);
                }
            }
        }
        
        return unique.size();
    }
};