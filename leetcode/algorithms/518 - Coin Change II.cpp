class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (auto& c: coins) {
            for (int i = 0; i <= amount - c; i++) {
                if (dp[i] > 0) {
                    dp[i + c] += dp[i];
                }
            }
        }
        
        return dp[amount];
    }
};
