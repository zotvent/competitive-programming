class Solution {
    
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int rows = heights.size();
        const int cols = heights[0].size();
        const vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        
        q.push({0, 0, 0});
        dp[0][0] = 0;
        
        while (!q.empty()) {
            auto cur = q.top();
            q.pop();
            
            int row = cur[1];
            int col = cur[2];
            
            for (auto& i: d) {
                int r = row + i[0];
                int c = col + i[1];
                
                if (valid(r, c, rows, cols)) {
                    int effort = abs(heights[row][col] - heights[r][c]);
                    
                    if (dp[r][c] > max(dp[row][col], effort)) {
                        dp[r][c] = max(dp[row][col], effort);
                        q.push({dp[r][c], r, c});
                    }
                }
            }
        }
        
        return dp[rows - 1][cols - 1];
    }
};