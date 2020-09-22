class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        vector<int> dp(n, 0);
        
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};