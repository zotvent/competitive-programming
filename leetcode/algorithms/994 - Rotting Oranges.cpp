class Solution {
    
    bool valid(int rows, int cols, int row, int col) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        
        queue<pair<int, int>> q;
        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size();
        int cols = (grid.empty()) ? 0 : grid[0].size();
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        vector<vector<int>> used(rows, vector<int>(cols, 0));
        int size, x, y;
        pair<int, int> v;
        
        while (!q.empty()) {
            size = q.size();
            res++;
            
            for (int i = 0; i < size; i++) {
                v = q.front();
                q.pop();
                
                for (int j = 0; j < d.size(); j++) {
                    x = v.first + d[j][0];
                    y = v.second + d[j][1];
                    
                    if (valid(rows, cols, x, y) && !used[x][y] && grid[x][y] == 1) {
                        q.push({x, y});
                        used[x][y] = 1;
                    }
                }
            }
        }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && !used[i][j]) {
                    res = -1;
                }
            }
        }
        
        return (res == -1) ? res : max(res - 1, 0);
    }
};