class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int n = 1e4 + 5;
        vector<int> dp(n, 0);
        
        for (auto& i: nums) {
            dp[i]++;
        }
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i] * i + dp[i - 2], dp[i - 1]);
        }
        
        return dp[n - 1];
    }
};