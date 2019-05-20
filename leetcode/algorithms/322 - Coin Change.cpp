class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; j <= amount - coins[i]; j++) {
                if (dp[j] < INT_MAX)
                    dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};