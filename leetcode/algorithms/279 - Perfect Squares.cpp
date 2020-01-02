class Solution {
public:
    int numSquares(int n) {
        int inf = (int) 1e9;
        vector<int> dp(n + 5, inf);
        dp[0] = 0;
        
        int mx = sqrt(n);
        int next;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= mx; j++) {
                next = i + j * j;
                
                if (next <= n && dp[next] > dp[i] + 1) {
                    dp[next] = dp[i] + 1;
                }
            }
        }
        
        return dp[n];
    }
};