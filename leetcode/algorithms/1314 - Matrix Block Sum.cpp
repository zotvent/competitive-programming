class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size();
        int m = (mat.empty() ? 0 : mat[0].size());
        
        // precalculation
        vector<vector<int>> dp = mat;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j) dp[i][j] += dp[i][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) dp[i][j] += dp[i - 1][j];
            }
        }
        
        // solution
        vector<vector<int>> res = mat;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = dp[min(n - 1, i + K)][min(m - 1, j + K)];
                
                if (j - K - 1 >= 0) {
                    res[i][j] -= dp[min(n - 1, i + K)][j - K - 1];
                }
                
                if (i - K - 1 >= 0) {
                    res[i][j] -= dp[i - K - 1][min(m - 1, j + K)];
                }
                
                if (i - K - 1 >= 0 && j - K - 1 >= 0) {
                    res[i][j] += dp[i - K - 1][j - K - 1];
                }
            }
        }
        
        
        return res;
    }
};