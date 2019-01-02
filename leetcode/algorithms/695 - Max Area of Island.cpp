class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> used(grid.size(), vector<int>(grid[0].size(), 0));
        int res = 0;
        
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (!used[i][j] && grid[i][j]) {
                    int temp = bfs(i, j, grid, used);
                    res = max(res, temp);
                }
        
        return res;
    }
    
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& used) {
        int res = 1;
        
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        used[row][col] = 1;
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        while (!q.empty()) {
            pair<int, int> v = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int x = v.first + dx[i];
                int y = v.second + dy[i];
                
                if (valid(x, y, grid)) {
                    if (grid[x][y] && !used[x][y]) {
                        res++;
                        used[x][y] = 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
        
        return res;
    }
    
    bool valid(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size();
    }
};