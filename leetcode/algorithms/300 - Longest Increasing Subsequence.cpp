class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size(), 0);
        
        for (int i = 0; i < dp.size(); i++) {
            dp[i] = 1;
            
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        for (int i = 0; i < dp.size(); i++)
            res = max(res, dp[i]);
        
        return res;
    }
};