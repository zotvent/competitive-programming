class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        vector< vector<int> > used(n, vector<int>(m, 0));
        
        bool isClosed;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !used[i][j]) {
                    isClosed = bfs(grid, i, j, used);
                
                    if (isClosed) {
                        res++;
                    }
                }
            }
        }
        
        return res;
    }
    
    bool bfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& used) {
        int n = grid.size();
        int m = grid[0].size();
        
        int max_row = row;
        int min_row = row;
        int max_col = col;
        int min_col = col;
        
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        used[row][col] = 1;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        pair<int, int> v;
        int r, c;
        
        while (!q.empty()) {
            v = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                r = v.first + dx[i];
                c = v.second + dy[i];
                
                if (valid(n, m, r, c) && !used[r][c] && grid[r][c] == 0) {
                    used[r][c] = 1;
                    q.push(make_pair(r, c));
                    
                    max_row = max(max_row, r);
                    min_row = min(min_row, r);
                    max_col = max(max_col, c);
                    min_col = min(min_col, c);
                }
            }
        }
        
        return min_row > 0 && min_col > 0 && max_row < n - 1 && max_col < m - 1;
    }
    
    bool valid(int rows, int cols, int row, int col) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
};