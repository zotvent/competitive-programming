class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1), updated(5, 1);
        
        for (int i = 2; i <= n; i++) {
            updated[0] = dp[0];
            for (int j = 1; j < dp.size(); j++) {
                updated[j] = updated[j - 1] + dp[j];
            }
            dp = updated;
        }
        
        int res = 0;
        for (auto& i: dp) {
            res += i;
        }
        
        return res;
    }
};