class Solution {
    
    bool valid(int row, int col, int n) {
        return row >= 0 && col >= 0 && row < n && col < n;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        const vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<int> cur;
        int r, c, size;
        
        q.push({0, 0});
        dp[0][0] = grid[0][0];
        
        while (!q.empty()) {
            size = q.size();
            for (; size > 0; size--) {
                cur = q.front();
                q.pop();
                
                for (int i = 0; i < d.size(); i++) {
                    r = cur[0] + d[i][0];
                    c = cur[1] + d[i][1];
                    
                    if (valid(r, c, n) && dp[r][c] > max(dp[cur[0]][cur[1]], grid[r][c])) {
                        q.push({r, c});
                        dp[r][c] = max(dp[cur[0]][cur[1]], grid[r][c]);
                    }
                }
            }
        }
        
        return dp[n - 1][n - 1];
    }
};