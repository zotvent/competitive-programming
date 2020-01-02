class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        int n = grid.size();
        int m = (grid.empty() ? 0 : grid[0].size());
        vector<vector<int>> used(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!used[i][j] && grid[i][j] == '1') {
                    bfs(grid, used, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& used, int row, int col) {
        int n = grid.size();
        int m = (grid.empty() ? 0 : grid[0].size());
        
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        used[row][col] = 1;
        
        pair<int, int> v;
        int sz, x, y;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            sz = q.size();
            
            for (int o = 0; o < sz; o++) {
                v = q.front();
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    x = v.first + dx[i];
                    y = v.second + dy[i];
                    
                    if (valid(x, y, n, m) && !used[x][y] && grid[x][y] == '1') {
                        q.push(make_pair(x, y));
                        used[x][y] = 1;
                    }
                }
            }
        }
    }
    
    bool valid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
};