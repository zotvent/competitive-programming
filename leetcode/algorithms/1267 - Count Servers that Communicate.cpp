class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        
        vector<vector<int>> used(grid.size(), vector<int>(grid[0].size(), 0));
        int tmp;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (!used[i][j] && grid[i][j]) {
                    tmp = bfs(grid, used, i, j);
                    if (tmp > 1) {
                        res += tmp;
                    }
                }
            }
        }
        
        return res;
    }
    
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& used, int row, int col) {
        int res = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        used[row][col] = 1;
        
        while (!q.empty()) {
            pair<int, int> v = q.front();
            int x = v.first;
            int y = v.second;
            q.pop();
            res++;
            
            // find on the same column
            for (int i = 0; i < n; i++) {
                if (!used[i][y] && grid[i][y]) {
                    q.push(make_pair(i, y));
                    used[i][y] = 1;
                }
            }
            
            // find on the same row
            for (int i = 0; i < m; i++) {
                if (!used[x][i] && grid[x][i]) {
                    q.push(make_pair(x, i));
                    used[x][i] = 1;
                }
            }
        }
        
        return res;
    }
};