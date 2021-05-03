class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int res = 0;
        const int rows = obstacleGrid.size();
        const int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        dp[0][0] = (obstacleGrid[0][0] == 0);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (obstacleGrid[i][j] == 0) {
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                }
            }
        }
        
        return dp[rows - 1][cols - 1];
    }
};