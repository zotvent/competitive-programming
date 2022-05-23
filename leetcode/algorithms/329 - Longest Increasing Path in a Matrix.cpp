class Solution {
    const vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col) {
        if (dp[row][col] != 0) return dp[row][col];
        
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        
        for (auto& i: d) {
            int r = row + i[0];
            int c = col + i[1];
            
            if (valid(r, c, rows, cols) && matrix[r][c] > matrix[row][col]) {
                dp[row][col] = max(dp[row][col], dfs(matrix, dp, r, c));
            }
        }
        
        return ++dp[row][col];
    }
    
    bool valid(int row, int col, int rows, int cols) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        
        return res;
    }
};