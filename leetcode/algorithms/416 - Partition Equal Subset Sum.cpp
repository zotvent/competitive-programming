class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for (auto& i: nums) {
            sum += i;
        }
        if (sum % 2 != 0) return false;
        
        const int n = nums.size();
        int half = sum / 2;
        vector<int> dp(half + 1, 0);
        dp[0] = 1;
        
        for (auto& i: nums) {
            for (int j = half; j >= i; j--) {
                if (dp[j - i]) {
                    dp[j] = 1;
                }
            }
        }
        
        return dp[half];
    }
};