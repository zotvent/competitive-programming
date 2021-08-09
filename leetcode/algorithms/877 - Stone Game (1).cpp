class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        const int n = piles.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        
        for (int size = 1; size <= n; size++) {
            for (int l = 0, r = size - 1; r < n; l++, r++) {
                int player = (l + r + n) % 2;
                
                if (player == 1) {
                    dp[l + 1][r + 1] = max(piles[l] + dp[l + 2][r + 1], piles[r] + dp[l + 1][r]);
                }
                else {
                    dp[l + 1][r + 1] = min(-piles[l] + dp[l + 2][r + 1], -piles[r] + dp[l + 1][r]);
                }
            }
        }
        
        return dp[1][n];
    }
};