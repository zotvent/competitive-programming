class Solution {
    
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int inf = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, inf));
        queue<vector<int>> q;
        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        if (!grid[0][0]) {
            q.push({0, 0});
            dp[0][0] = 1;
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
                    
                    if (valid(r, c, n, n) && !grid[r][c] && dp[r][c] > dp[row][col] + 1) {
                        dp[r][c] = dp[row][col] + 1;
                        q.push({r, c});
                    }
                }
            }
        }
        
        return (dp[n - 1][n - 1] == inf ? -1 : dp[n - 1][n - 1]);
    }
};