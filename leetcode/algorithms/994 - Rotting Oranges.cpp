class Solution {
    
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        const vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<vector<int>> q;
        int fresh = 0, minutes = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        if (fresh == 0) {
            return minutes;
        }
        
        while (!q.empty()) {
            int size = q.size();
            
            for (; size > 0; size--) {
                int row = q.front()[0];
                int col = q.front()[1];
                q.pop();
                
                for (auto& i: d) {
                    int r = row + i[0];
                    int c = col + i[1];
                    
                    if (valid(r, c, rows, cols) && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    }
                }
            }
            
            minutes++;
        }
        
        return (fresh == 0 ? minutes - 1 : -1);
    }
};