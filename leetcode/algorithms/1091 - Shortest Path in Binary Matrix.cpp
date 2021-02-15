class Solution {
    
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = (grid.empty() ? 0 : grid[0].size());
        
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        queue<vector<int>> q;
        vector<int> cur;
        int x, y, size;
        
        if (grid[0][0] == 0) {
            q.push({0, 0});
            dp[0][0] = 1;
        }
        
        while (!q.empty()) {
            size = q.size();
            
            for (; size > 0; size--) {
                cur = q.front();
                q.pop();
                
                for (int i = 0; i < d.size(); i++) {
                    x = cur[0] + d[i][0];
                    y = cur[1] + d[i][1];
                    
                    if (valid(x, y, rows, cols) && !grid[x][y] && dp[x][y] > dp[cur[0]][cur[1]] + 1) {
                        q.push({x, y});
                        dp[x][y] = dp[cur[0]][cur[1]] + 1;
                    }
                }
            }
        }
        
        return (dp[rows - 1][cols - 1] == INT_MAX ? -1 : dp[rows - 1][cols - 1]);
    }
};