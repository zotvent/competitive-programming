class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> dp(n, 1);
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                dp[i] = max(dp[i], dp[i + 1] + 1);
            }
        }
        
        int res = 0;
        for (auto& i: dp) res += i;        
        return res;
    }
};