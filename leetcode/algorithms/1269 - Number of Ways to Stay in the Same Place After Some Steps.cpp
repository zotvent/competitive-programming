class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = (int) 1e9 + 7;
        
        vector<int> dp(arrLen, 0), next(arrLen, 0);
        dp[0] = dp[1] = 1;
        int size = min(steps / 2, arrLen - 1);
        int j;
        
        for (int i = 2; i <= steps; i++) {
            j = 0;
            
            while (j <= size && dp[max(0, j - 1)] > 0) {
                next[j] = dp[j];
                if (j > 0) next[j] = (next[j] + dp[j - 1]) % mod;
                if (j < size) next[j] = (next[j] + dp[j + 1]) % mod;
                
                j++;
            }
            
            dp = next;
        }
        
        return dp[0];
    }
};